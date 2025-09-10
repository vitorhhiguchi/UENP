// server.js - Versão CORRIGIDA

const WebSocket = require('ws');
const gamepad = require('gamepad'); // <-- Esta é a linha correta

// --- Configuração do Servidor WebSocket (igual antes) ---
const wss = new WebSocket.Server({ port: 8080 });
console.log('Servidor WebSocket iniciado na porta 8080.');
console.log('Aguardando conexão do ESP32...');

wss.on('connection', ws => {
    console.log('Cliente (ESP32) conectado!');
    ws.on('message', message => {
        console.log(`Mensagem recebida do ESP32: ${message}`);
    });
    ws.on('close', () => {
        console.log('Cliente desconectado.');
    });
});

// --- Lógica do Gamepad ---

// Inicializa o leitor de gamepad
gamepad.init();
console.log('Procurando por controles... Conecte o seu controle de PS5.');

let lastCommand = 'PARAR';

function sendCommand(command) {
    if (command !== lastCommand) {
        if (wss.clients.size > 0) {
            wss.clients.forEach(client => {
                if (client.readyState === WebSocket.OPEN) {
                    client.send(command);
                    console.log(`Comando enviado: ${command}`);
                }
            });
            lastCommand = command;
        }
    }
}

// O loop para processar eventos do controle mudou um pouco para esta biblioteca
setInterval(gamepad.processEvents, 16); // Recomenda-se 16ms para ~60Hz

// Escuta por eventos de movimento nos joysticks
gamepad.on('move', (id, axis, value) => {
    let currentCommand = lastCommand; // Começa com o último comando válido

    // Joystick Esquerdo (Vertical: para frente/trás) - Geralmente eixo 1
    if (axis === 1) {
        if (value < -0.5) {
            currentCommand = 'FRENTE';
        } else if (value > 0.5) {
            currentCommand = 'TRAS';
        } else if (lastCommand === 'FRENTE' || lastCommand === 'TRAS') {
             // Se o joystick voltou ao centro, pare
            currentCommand = 'PARAR';
        }
    }

    // Joystick Direito (Horizontal: para esquerda/direita) - Geralmente eixo 2
    if (axis === 2) {
        if (value < -0.5) {
            currentCommand = 'ESQUERDA';
        } else if (value > 0.5) {
            currentCommand = 'DIREITA';
        } else if (lastCommand === 'ESQUERDA' || lastCommand === 'DIREITA') {
             // Se o joystick voltou ao centro, pare
            currentCommand = 'PARAR';
        }
    }
    
    sendCommand(currentCommand);
});


gamepad.on('attach', (id, state) => {
    console.log(`Controle ${id} conectado! Marca: ${state.product}`);
});

gamepad.on('detach', (id) => {
    console.log(`Controle ${id} desconectado.`);
});