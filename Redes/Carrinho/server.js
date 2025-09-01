// server.js
const WebSocket = require("ws");

const wss = new WebSocket.Server({ port: 8080 });

// Mapas para guardar conexões
let cars = {};      // {carId: ws}
let users = {};     // {userId: { ws, carId }}

wss.on("connection", (ws) => {
  console.log("Nova conexão recebida");

  ws.on("message", (msg) => {
    try {
      const data = JSON.parse(msg);

      // ESP32 se conectando
      if (data.type === "register_car") {
        const { carId } = data;
        cars[carId] = ws;
        ws.carId = carId;
        console.log(`🚗 Carro registrado: ${carId}`);
        ws.send(JSON.stringify({ type: "registered", carId }));
      }

      // Usuário se conectando
      else if (data.type === "register_user") {
        const { userId } = data;
        users[userId] = { ws, carId: null };
        ws.userId = userId;
        console.log(`🙋 Usuário registrado: ${userId}`);
        ws.send(JSON.stringify({ type: "registered", userId, cars: Object.keys(cars) }));
      }

      // Usuário seleciona carro
      else if (data.type === "select_car") {
        const { userId, carId } = data;
        if (!cars[carId]) {
          ws.send(JSON.stringify({ type: "error", message: "Carro não disponível" }));
          return;
        }

        // Verifica se já está sendo usado
        const inUse = Object.values(users).some(u => u.carId === carId);
        if (inUse) {
          ws.send(JSON.stringify({ type: "error", message: "Carro já está em uso" }));
          return;
        }

        users[userId].carId = carId;
        console.log(`✅ Usuário ${userId} conectado ao carro ${carId}`);
        ws.send(JSON.stringify({ type: "car_selected", carId }));
      }

      // Usuário manda comando para o carro
      else if (data.type === "command") {
        const { userId, command } = data;
        const carId = users[userId]?.carId;
        if (carId && cars[carId]) {
          cars[carId].send(JSON.stringify({ type: "command", command }));
        }
      }

      // Carro manda status
      else if (data.type === "status") {
        const { carId, status } = data;
        // Procura usuário conectado a este carro
        const user = Object.values(users).find(u => u.carId === carId);
        if (user) {
          user.ws.send(JSON.stringify({ type: "status", carId, status }));
        }
      }

    } catch (err) {
      console.error("Erro ao processar mensagem:", err);
    }
  });

  ws.on("close", () => {
    if (ws.carId) {
      console.log(`Carro desconectado: ${ws.carId}`);
      delete cars[ws.carId];
    }
    if (ws.userId) {
      console.log(`Usuário desconectado: ${ws.userId}`);
      delete users[ws.userId];
    }
  });
});

console.log("Servidor rodando na porta 8080 🚀");