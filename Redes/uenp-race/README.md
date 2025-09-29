# Sistema de Controle de Carros

Sistema web para controle remoto de carros via ESP32 com autenticação de usuários.

## Funcionalidades

- 🔐 **Autenticação de usuários** com login e senha
- 🚗 **Lista de carros disponíveis** em tempo real
- 🎮 **Controle remoto** com botões e teclado
- 📹 **Transmissão de vídeo** ao vivo
- 🔄 **Conexão WebSocket** para comunicação em tempo real

## Como usar

### 1. Iniciar o servidor
```bash
node server.js
```

### 2. Acessar o sistema
Abra o navegador e vá para: `http://localhost:8080`

### 3. Fazer login
Use uma das credenciais cadastradas no arquivo `users.json`:
- **admin** / **admin123**
- **usuario1** / **senha123**
- **usuario2** / **senha456**
- **teste** / **teste123**

### 4. Selecionar carro
Na página de carros disponíveis, clique em "Selecionar Carro" no carro desejado.

### 5. Controlar o carro
Na página de controle, você pode:
- **Usar os botões** na tela para controlar o carro
- **Usar as setas do teclado**:
  - ⬆️ Seta para cima - Frente
  - ⬇️ Seta para baixo - Trás
  - ⬅️ Seta para esquerda - Esquerda
  - ➡️ Seta para direita - Direita
- **Usar controle PlayStation** (conectado via Bluetooth):
  - D-Pad para movimentos discretos
  - Analógico esquerdo para movimentos suaves

## Estrutura do projeto

```
servidor/
├── server.js          # Servidor principal (HTTP + WebSocket)
├── index.html         # Página de login
├── carros.html        # Página de seleção de carros
├── controle.html      # Página de controle do carro
├── users.json         # Arquivo de usuários e senhas
└── README.md          # Este arquivo
```

## Configuração do ESP32

Para conectar um carro ESP32 ao sistema, o ESP32 deve enviar uma mensagem WebSocket para o servidor:

```json
{
  "type": "register_car",
  "carId": "carro-esp32-01",
  "streamUrl": "http://192.168.1.100:81/stream"
}
```

### Comandos recebidos pelo ESP32

O ESP32 receberá comandos no formato:

**Comandos discretos (teclado, mouse, D-Pad do controle):**
```json
{
  "type": "command",
  "command": "forward" | "backward" | "left" | "right"
}
```

**Comandos analógicos (analógico do controle PlayStation):**
```json
{
  "type": "analog_command",
  "x": -1.0,  // Valor de -1.0 (esquerda) a 1.0 (direita)
  "y": -1.0   // Valor de -1.0 (trás) a 1.0 (frente)
}
```

## Protocolo WebSocket

### Conexão do usuário do browser

Quando um usuário se conecta via browser, ele envia:
```json
{
  "type": "register_user",
  "userId": "admin"
}
```

O servidor responde com:
```json
{
  "type": "registered",
  "userId": "admin",
  "cars": [
    {
      "carId": "carro-esp32-01",
      "streamUrl": "http://192.168.1.187:81/stream"
    }
  ]
}
```

### Seleção de carro

Para selecionar um carro, o usuário envia:
```json
{
  "type": "select_car",
  "userId": "admin",
  "carId": "carro-esp32-01"
}
```

O servidor responde com:
```json
{
  "type": "car_selected",
  "carId": "carro-esp32-01"
}
```

### Envio de comandos

**Comandos discretos (teclado/mouse/D-Pad):**
```json
{
  "type": "command",
  "userId": "admin",
  "command": "forward"
}
```

**Comandos analógicos (analógico do controle):**
```json
{
  "type": "analog_command",
  "userId": "admin",
  "x": 0.5,
  "y": -0.8
}
```

## Adicionando novos usuários

Edite o arquivo `users.json` para adicionar novos usuários:

```json
{
  "admin": "admin123",
  "usuario1": "senha123",
  "novo_usuario": "nova_senha"
}
```

## Portas utilizadas

- **8080**: Servidor HTTP e WebSocket
- **81**: Stream de vídeo do ESP32 (configurável)

## Tecnologias utilizadas

- **Node.js** - Servidor backend
- **WebSocket** - Comunicação em tempo real
- **HTML5/CSS3/JavaScript** - Interface web
- **ESP32** - Hardware do carro
