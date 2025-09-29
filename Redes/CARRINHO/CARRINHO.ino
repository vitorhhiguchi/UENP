#include <WiFi.h>
#include <WebSocketsClient.h>
#include <ESP32Servo.h>
#include <ArduinoJson.h>

// --- CONFIGURAÇÕES DE REDE E DO CARRINHO---
const char* ssid = "UENP-RACE";
const char* password = "competidor";
const char* websocket_server_host = "192.168.1.100"; // 192.168.1.100
const uint16_t websocket_server_port = 8080; 

// --- DADOS ESPECÍFICOS DO CARRINHO ---
const char* carIdentifier = "Jeep-Mullet"; // ID único para o seu carrinho

// ALTERAÇÃO 1: Usar o objeto String para a URL, que gerencia a memória automaticamente
String streamURL; 

// --- DEFINIÇÕES DE HARDWARE (sem alterações) ---
Servo steeringServo;
int steeringPin = 25;
int enableRightMotor = 22;
int rightMotorPin1 = 16;
int rightMotorPin2 = 17;
int enableLeftMotor = 23;
int leftMotorPin1 = 18;
int leftMotorPin2 = 19;
const int PWMFreq = 1000;
const int PWMResolution = 8;
const int rightMotorPWMSpeedChannel = 4;
const int leftMotorPWMSpeedChannel = 5;

// --- OBJETOS DE CLIENTE ---
WebSocketsClient webSocket;

// ===================================================================================
// FUNÇÕES DE CONTROLE DE HARDWARE (Sem alterações)
// ===================================================================================
void rotateMotor(int rightMotorSpeed, int leftMotorSpeed) {
    if (rightMotorSpeed < 0) {
        digitalWrite(rightMotorPin1, LOW);
        digitalWrite(rightMotorPin2, HIGH);
    } else if (rightMotorSpeed > 0) {
        digitalWrite(rightMotorPin1, HIGH);
        digitalWrite(rightMotorPin2, LOW);
    } else {
        digitalWrite(rightMotorPin1, LOW);
        digitalWrite(rightMotorPin2, LOW);
    }
    if (leftMotorSpeed < 0) {
        digitalWrite(leftMotorPin1, LOW);
        digitalWrite(leftMotorPin2, HIGH);
    } else if (leftMotorSpeed > 0) {
        digitalWrite(leftMotorPin1, HIGH);
        digitalWrite(leftMotorPin2, LOW);
    } else {
        digitalWrite(leftMotorPin1, LOW);
        digitalWrite(leftMotorPin2, LOW);
    }
    ledcWrite(rightMotorPWMSpeedChannel, abs(rightMotorSpeed));
    ledcWrite(leftMotorPWMSpeedChannel, abs(leftMotorSpeed));
}

void setUpPinModes() {
    steeringServo.attach(steeringPin);
    pinMode(enableRightMotor, OUTPUT);
    pinMode(rightMotorPin1, OUTPUT);
    pinMode(rightMotorPin2, OUTPUT);
    pinMode(enableLeftMotor, OUTPUT);
    pinMode(leftMotorPin1, OUTPUT);
    pinMode(leftMotorPin2, OUTPUT);
    ledcSetup(rightMotorPWMSpeedChannel, PWMFreq, PWMResolution);
    ledcSetup(leftMotorPWMSpeedChannel, PWMFreq, PWMResolution);
    ledcAttachPin(enableRightMotor, rightMotorPWMSpeedChannel);
    ledcAttachPin(enableLeftMotor, leftMotorPWMSpeedChannel);
    rotateMotor(0, 0);
    steeringServo.write(98);
}

// ===================================================================================
// FUNÇÃO PARA REGISTRAR O CARRINHO
// ===================================================================================
void registerCar() {
    JsonDocument doc;

    doc["type"] = "register_car";
    doc["carId"] = carIdentifier;
    // ALTERAÇÃO 2: ArduinoJson sabe como usar o objeto String diretamente
    doc["streamUrl"] = streamURL;
    
    String output;
    serializeJson(doc, output);
    
    webSocket.sendTXT(output);
    
    Serial.println("\n[WebSocket] Mensagem de registro enviada:");
    Serial.println(output);
}

// ===================================================================================
// LÓGICA DE WEBSOCKET (Sem alterações na lógica principal)
// ===================================================================================
void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
    switch(type) {
        case WStype_DISCONNECTED:
            Serial.println("[WebSocket] Desconectado!");
            rotateMotor(0, 0);
            steeringServo.write(98);
            break;
        case WStype_CONNECTED:
            Serial.println("[WebSocket] Conectado ao servidor!");
            registerCar();
            break;
        case WStype_TEXT: {
            JsonDocument doc;
            DeserializationError error = deserializeJson(doc, payload, length);
            if (error) {
                Serial.print(F("deserializeJson() falhou: "));
                Serial.println(error.c_str());
                return;
            }
            const char* messageType = doc["type"];
            if (strcmp(messageType, "analog_command") == 0) {
              float y_axis = doc["y"];
              float x_axis = doc["x"];
              int throttle = map(y_axis * 100, -100, 100, 255, -255);
              int steering = map(x_axis * 100, -100, 100, 135, 30);
              rotateMotor(throttle, throttle);
              steeringServo.write(steering);
            }
            break;
        }
    }
}

// ===================================================================================
// SETUP E LOOP PRINCIPAL
// ===================================================================================
void setup() {
    Serial.begin(115200);
    setUpPinModes();
    
    WiFi.begin(ssid, password);
    Serial.print("Conectando ao Wi-Fi ");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConectado ao Wi-Fi!");
    Serial.print("Endereço IP do ESP32: ");
    Serial.println(WiFi.localIP());

    // ALTERAÇÃO 3: Construir a URL diretamente no objeto String global
    streamURL = "http://192.168.1.3:81/stream";

    webSocket.begin(websocket_server_host, websocket_server_port, "/");
    webSocket.onEvent(webSocketEvent);
    webSocket.setReconnectInterval(5000);
}

void loop() {
  webSocket.loop();
}