// register_car_client.js
const WebSocket = require("ws");

// --- Definições ---
const SERVER_URL = "ws://172.16.3.45:8080";
const MEU_CARRO_ID = "TESTANDO"; // ID único para seu carro/ESP32

// 1. Cria a conexão com o servidor
console.log(`🚗 Tentando conectar ao servidor em ${SERVER_URL}...`);
const ws = new WebSocket(SERVER_URL);

// 2. Evento que dispara quando a conexão é estabelecida
ws.on("open", () => {
  console.log("✅ Conexão bem-sucedida!");

  // Prepara a mensagem de registro do carro
  const registrationMessage = {
    type: "register_car",
    carId: MEU_CARRO_ID,
  };

  // Envia a mensagem para o servidor
  ws.send(JSON.stringify(registrationMessage));
  
  console.log(`🚗 Mensagem de registro enviada:`, registrationMessage);
});

// 3. Evento que dispara ao receber uma mensagem do servidor
ws.on("message", (message) => {
  const data = JSON.parse(message);
  console.log("📩 Mensagem recebida do servidor:", data);

  // O servidor deve confirmar o registro
  if (data.type === "registered" && data.carId === MEU_CARRO_ID) {
    console.log(`🎉 Carro '${data.carId}' registrado com sucesso!`);
    console.log("   Agora o carro está 'online' e pronto para receber comandos.");
  }
  
  // Aqui você adicionaria a lógica para tratar comandos recebidos
  if (data.type === "command") {
    console.log(`🔧 Comando recebido: '${data.command}'. Executando...`);
    // Aqui viria a lógica para controlar o motor, etc.
  }
});

// Evento que dispara quando a conexão é fechada
ws.on("close", () => {
  console.log("🔌 Conexão com o servidor foi perdida.");
});

// Evento para tratar erros de conexão
ws.on("error", (error) => {
  console.error("❌ Erro na conexão:", error.message);
});