// client.js
const WebSocket = require("ws");

const SERVER_URL = "ws://172.16.3.45:8080";

// --- SIMULAÇÃO DO CARRO (ESP32) ---
function startCarClient() {
  const carId = "carro1";
  const car_ws = new WebSocket(SERVER_URL);

  car_ws.on("open", () => {
    console.log(`🚗 [CARRO] Conectado ao servidor.`);
    // 1. Carro se registra
    const message = { type: "register_car", carId };
    car_ws.send(JSON.stringify(message));
    console.log(`🚗 [CARRO] Enviando registro:`, message);
  });

  car_ws.on("message", (msg) => {
    const data = JSON.parse(msg);
    console.log(`🚗 [CARRO] Mensagem recebida do servidor:`, data);

    // O carro pode receber comandos do usuário
    if (data.type === "command") {
      console.log(`🚗 [CARRO] >>> Comando '${data.command}' recebido! Executando ação...`);
      // Simula o envio de um status de volta após executar o comando
      setTimeout(() => {
        const statusMessage = {
          type: "status",
          carId,
          status: { action: data.command, battery: "95%" },
        };
        car_ws.send(JSON.stringify(statusMessage));
        console.log(`🚗 [CARRO] Enviando status:`, statusMessage);
      }, 500); // espera 0.5s para responder
    }
  });

  car_ws.on("close", () => {
    console.log("🚗 [CARRO] Desconectado do servidor.");
  });

  car_ws.on("error", (err) => {
    console.error("🚗 [CARRO] Erro na conexão:", err.message);
  });
}

// --- SIMULAÇÃO DO USUÁRIO (APP/SITE) ---
function startUserClient() {
  const userId = "Vitor";
  const user_ws = new WebSocket(SERVER_URL);

  user_ws.on("open", () => {
    console.log(`🙋 [USUÁRIO] Conectado ao servidor.`);
    // 2. Usuário se registra
    const message = { type: "register_user", userId };
    user_ws.send(JSON.stringify(message));
    console.log(`🙋 [USUÁRIO] Enviando registro:`, message);
  });

  user_ws.on("message", (msg) => {
    const data = JSON.parse(msg);
    console.log(`🙋 [USUÁRIO] Mensagem recebida do servidor:`, data);

    // 3. Usuário recebe a lista de carros e escolhe um
    if (data.type === "registered" && data.cars) {
      const targetCarId = "carro1";
      if (data.cars.includes(targetCarId)) {
        console.log(`🙋 [USUÁRIO] Carro '${targetCarId}' disponível. Selecionando...`);
        const message = { type: "select_car", userId, carId: targetCarId };
        user_ws.send(JSON.stringify(message));
        console.log(`🙋 [USUÁRIO] Enviando seleção de carro:`, message);
      } else {
        console.log(`🙋 [USUÁRIO] Carro '${targetCarId}' não encontrado.`);
      }
    }

    // 4. Servidor confirma a seleção, usuário manda o comando
    else if (data.type === "car_selected") {
      console.log(`🙋 [USUÁRIO] Carro '${data.carId}' selecionado com sucesso.`);
      // Adiciona um pequeno delay para o fluxo ficar mais claro no console
      setTimeout(() => {
        const command = "forward";
        const message = { type: "command", userId, command };
        user_ws.send(JSON.stringify(message));
        console.log(`🙋 [USUÁRIO] Enviando comando '${command}':`, message);
      }, 1000); // espera 1s
    }
    
    // Usuário recebe o status do carro
    else if (data.type === "status") {
        console.log(`🙋 [USUÁRIO] <<< Status recebido do carro ${data.carId}:`, data.status);
    }
    
    // Tratamento de erros vindos do servidor
    else if (data.type === "error") {
        console.error(`🙋 [USUÁRIO] Erro do servidor: ${data.message}`);
    }
  });

  user_ws.on("close", () => {
    console.log("🙋 [USUÁRIO] Desconectado do servidor.");
  });

  user_ws.on("error", (err) => {
    console.error("🙋 [USUÁRIO] Erro na conexão:", err.message);
  });
}

// Inicia as duas simulações
// Adicionamos um pequeno atraso para o usuário se conectar logo após o carro
startCarClient();
setTimeout(startUserClient, 500); // O usuário conecta 0.5s depois