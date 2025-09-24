// server.js - Versão Relé (Repassador de Mensagens)

const WebSocket = require('ws');

const wss = new WebSocket.Server({ port: 8080 });

console.log('Servidor WebSocket (Relé) iniciado na porta 8080.');
console.log('Aguardando conexões do painel de controle e do carrinho...');

wss.on('connection', ws => {
    console.log('Um cliente se conectou.');

    // Esta é a parte principal.
    // Quando um cliente (a página web) envia uma mensagem...
    ws.on('message', message => {
        // ...nós a enviamos para todos os outros clientes conectados (o carrinho).
        console.log(`Mensagem recebida: ${message}. Repassando...`);
        
        wss.clients.forEach(client => {
            // A condição `client !== ws` garante que não enviemos a mensagem de volta
            // para quem a enviou originalmente.
            if (client !== ws && client.readyState === WebSocket.OPEN) {
                client.send(message.toString());
            }
        });
    });

    ws.on('close', () => {
        console.log('Um cliente se desconectou.');
    });
});