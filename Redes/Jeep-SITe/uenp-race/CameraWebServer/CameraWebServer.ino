#include "esp_camera.h"
#include <WiFi.h>
#include <WebSocketsClient.h>
#include <ArduinoJson.h>

// ===========================
// Select camera model in board_config.h
// ===========================
#include "board_config.h"

// ===========================
// Enter your WiFi credentials
// ===========================
const char *ssid = "UENP-RACE";
const char *password = "******";

// ===========================
// WebSocket
// ===========================
const char* websocket_server = "192.168.1.100";  // IP do seu servidor Node
const int websocket_port = 8080;
const char* websocket_path = "/ws";

WebSocketsClient webSocket;

String carId = "carro-esp32-01";  //Nome da sua equipe

void startCameraServer();

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.frame_size = FRAMESIZE_UXGA;
  config.pixel_format = PIXFORMAT_JPEG;  // for streaming
  //config.pixel_format = PIXFORMAT_RGB565; // for face detection/recognition
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.jpeg_quality = 20;
  config.fb_count = 1;

  // if PSRAM IC present, init with UXGA resolution and higher JPEG quality
  //                      for larger pre-allocated frame buffer.
  if (config.pixel_format == PIXFORMAT_JPEG) {
    if (psramFound()) {
      config.jpeg_quality = 10;
      config.fb_count = 2;
      config.grab_mode = CAMERA_GRAB_LATEST;
    } else {
      // Limit the frame size when PSRAM is not available
      config.frame_size = FRAMESIZE_SVGA;
      config.fb_location = CAMERA_FB_IN_DRAM;
    }
  } else {
    // Best option for face detection/recognition
    config.frame_size = FRAMESIZE_240X240;
#if CONFIG_IDF_TARGET_ESP32S3
    config.fb_count = 2;
#endif
  }

#if defined(CAMERA_MODEL_ESP_EYE)
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
#endif

  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  sensor_t *s = esp_camera_sensor_get();
  // initial sensors are flipped vertically and colors are a bit saturated
  if (s->id.PID == OV3660_PID) {
    s->set_vflip(s, 1);        // flip it back
    s->set_brightness(s, 1);   // up the brightness just a bit
    s->set_saturation(s, -2);  // lower the saturation
  }
  // drop down frame size for higher initial frame rate
  if (config.pixel_format == PIXFORMAT_JPEG) {
    s->set_framesize(s, FRAMESIZE_QVGA);
  }

#if defined(CAMERA_MODEL_M5STACK_WIDE) || defined(CAMERA_MODEL_M5STACK_ESP32CAM)
  s->set_vflip(s, 1);
  s->set_hmirror(s, 1);
#endif

#if defined(CAMERA_MODEL_ESP32S3_EYE)
  s->set_vflip(s, 1);
#endif

  WiFi.begin(ssid, password);
  WiFi.setSleep(false);

  Serial.print("WiFi connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  startCameraServer();

  Serial.print("Camera Ready! Use 'http://");
  Serial.print(WiFi.localIP());
  Serial.println("' to connect");

webSocket.begin(websocket_server, websocket_port, websocket_path);
webSocket.onEvent([](WStype_t type, uint8_t * payload, size_t length) {
  if (type == WStype_CONNECTED) {
    Serial.println("✅ Conectado ao servidor WebSocket!");

    // monta a URL de stream com IP local do ESP32
    String streamUrl = "http://" + WiFi.localIP().toString() + ":81/stream";

    // envia JSON de registro
    DynamicJsonDocument doc(256);
    doc["type"] = "register_car";
    doc["carId"] = carId;
    doc["streamUrl"] = streamUrl;

    String json;
    serializeJson(doc, json);

    webSocket.sendTXT(json);
    Serial.println("📡 Registro enviado: " + json);
  }
  else if (type == WStype_DISCONNECTED) {
    Serial.println("⚠️ Desconectado do WebSocket!");
  }
  else if (type == WStype_TEXT) {
    Serial.printf("📨 Mensagem recebida: %s\n", payload);

    DynamicJsonDocument msg(512);
    DeserializationError error = deserializeJson(msg, payload);

    if (error) {
      Serial.println("❌ Erro ao interpretar JSON recebido");
      return;
    }

    String msgType = msg["type"] | "";

    if (msgType == "registered") {
      // 🔹 Confirmação de registro do carro no servidor
      Serial.println("📌 Registro confirmado pelo servidor");
    }
    else if (msgType == "command") {
      // 🔹 Comando digital (frente, trás, esquerda, direita, parar, etc.)
      String command = msg["command"] | "";
      Serial.println("🎮 Comando recebido: " + command);

      // 👉 Aqui você coloca a lógica para mover o carrinho
      // Exemplo:
      // if (command == "forward") motorForward();
      // else if (command == "backward") motorBackward();
      // else if (command == "left") turnLeft();
      // else if (command == "right") turnRight();
      // else if (command == "stop") motorStop();
    }
    else if (msgType == "analog_command") {
      // 🔹 Comando analógico (joystick) com valores X e Y
      float x = msg["x"] | 0.0;
      float y = msg["y"] | 0.0;
      Serial.printf("🎮 Comando analógico recebido: X=%.2f, Y=%.2f\n", x, y);

      // 👉 Aqui você adapta para controle proporcional dos motores
      // exemplo: mapear x/y para velocidade do motor
    }
    else if (msgType == "status") {
      // 🔹 Atualização de status (opcional)
      String status = msg["status"] | "";
      Serial.println("📡 Status recebido: " + status);
    }
    else if (msgType == "error") {
      // 🔹 Mensagem de erro vinda do servidor
      String errMsg = msg["message"] | "Erro desconhecido";
      Serial.println("⚠️ Erro recebido do servidor: " + errMsg);
    }
  }
});
webSocket.setReconnectInterval(5000);
}

void loop() {
  webSocket.loop();
}
