# ESP32 RaceCar - Sistema de Câmera com WebSocket

Este projeto implementa um sistema de câmera ESP32 que se conecta a um servidor Node.js via WebSocket para streaming de vídeo em tempo real, desenvolvido para o projeto RaceCar 2025 da UENP.

## 📋 Visão Geral

O sistema consiste em:
- **ESP32 com câmera** (AI-Thinker ESP32-CAM)
- **Servidor WebSocket** para comunicação
- **Streaming de vídeo** em tempo real
- **Registro automático** do carro no servidor

## 🔧 Hardware

### Placa Utilizada
- **Modelo**: AI-Thinker ESP32-CAM
- **PSRAM**: Sim (necessário para resolução UXGA)
- **Câmera**: OV2640 (2MP, suporte a JPEG)
- **Resolução**: 640x480 (VGA) - otimizada para streaming
- **Formato**: JPEG otimizado para streaming


## 🌐 Configuração de Rede

### WiFi
```cpp
const char *ssid = "UENP-RACE";
const char *password = "****";
```

### WebSocket
```cpp
const char* websocket_server = "192.168.1.100";  // IP do servidor Node
const int websocket_port = 8080;
const char* websocket_path = "/ws";
```

## 📁 Estrutura do Projeto

```
CameraWebServer/
├── CameraWebServer.ino    # Arquivo principal
├── app_httpd.cpp          # Servidor HTTP para streaming
├── board_config.h         # Configuração da placa
├── camera_pins.h          # Definições de pinos
└── camera_index.h         # Interface web
```

## 🚀 Funcionalidades

### 1. Inicialização da Câmera
- Configuração automática baseada no modelo da placa
- Otimização para PSRAM quando disponível
- Ajustes de qualidade e resolução

### 2. Conexão WiFi
- Conexão automática à rede configurada
- Indicadores visuais de status
- Configuração para evitar sleep do WiFi

### 3. Servidor de Streaming
- Servidor HTTP na porta 81
- Endpoint `/stream` para streaming MJPEG
- Interface web para visualização

### 4. Comunicação WebSocket
- Conexão automática ao servidor Node.js
- Registro do carro com ID único
- Envio da URL de streaming
- Reconexão automática em caso de falha


## 📡 Protocolo de Comunicação

### Registro do Carro
```json
{
  "type": "register_car",
  "carId": "carro-esp32-01",
  "streamUrl": "http://192.168.1.xxx:81/stream"
}
```

### Tipos de Mensagem

#### Enviadas pelo ESP32:
- `register_car`: Registro inicial do carro
- `status`: Status periódico do carro

#### Recebidas pelo ESP32:
- `command`: Comandos digitais (forward, backward, left, right, stop, etc.)
- `analog_command`: Comandos analógicos com coordenadas X,Y
- `registered`: Confirmação de registro

#### Comandos Digitais Suportados:
- `forward`: Frente
- `backward`: Ré
- `left`: Esquerda (rotação no local)
- `right`: Direita (rotação no local)
- `stop`: Parar
- `forward_left`: Frente + esquerda
- `forward_right`: Frente + direita
- `backward_left`: Ré + esquerda
- `backward_right`: Ré + direita

#### Comandos Analógicos:
```json
{
  "type": "analog_command",
  "x": -1.0,  // -1 (esquerda) a 1 (direita)
  "y": 0.5    // -1 (ré) a 1 (frente)
}
```

#### Status do Carro:
```json
{
  "type": "status",
  "carId": "carro-esp32-01",
  "status": {
    "motorSpeed": 200,
    "motorDirection": 1,
    "steeringDirection": 0,
    "wifiRSSI": -45,
    "freeHeap": 150000,
    "uptime": 120
  }
}
```

## ⚙️ Configuração e Instalação

### 1. Requisitos
- Arduino IDE com ESP32 Core
- Placa ESP32-CAM com PSRAM
- Servidor Node.js rodando na rede

### 2. Configuração do Arduino IDE
1. Instale o ESP32 Core via Board Manager
2. Selecione a placa "AI Thinker ESP32-CAM"
3. Configure a partição com pelo menos 3MB de espaço APP

### 3. Configurações Necessárias
1. **WiFi**: Atualize `ssid` e `password` no código
2. **Servidor**: Configure o IP do servidor WebSocket
3. **ID do Carro**: Personalize o `carId` com o nome da sua equipe

### 4. Upload do Código
1. Conecte o ESP32-CAM ao computador
2. Mantenha o botão BOOT pressionado durante o upload
3. Solte o botão após iniciar o upload

## 🔍 Monitoramento

### Serial Monitor
- Baudrate: 115200
- Logs de conexão WiFi
- Status da câmera
- Mensagens WebSocket
- URLs de acesso

### Indicadores Visuais
- LED integrado (GPIO 4) para status
- Logs detalhados no Serial Monitor

## 🌐 Acesso ao Sistema

### Streaming de Vídeo
```
http://[IP_DO_ESP32]:81/stream
```

### Interface Web
```
http://[IP_DO_ESP32]:81
```

### Exemplo de IP
```
http://192.168.1.100:81/stream
```

## 🛠️ Solução de Problemas

### Problemas Comuns

1. **Câmera não inicializa**
   - Verifique se a placa tem PSRAM
   - Confirme a configuração de partição
   - Verifique as conexões dos pinos

2. **WiFi não conecta**
   - Verifique credenciais de rede
   - Confirme força do sinal
   - Verifique configuração de canal

3. **WebSocket não conecta**
   - Verifique IP do servidor
   - Confirme se o servidor está rodando
   - Verifique firewall da rede

4. **Streaming com baixa qualidade**
   - Ajuste `jpeg_quality` (menor = melhor qualidade)
   - Verifique disponibilidade de PSRAM
   - Reduza resolução se necessário

5. **Erro de inicialização da câmera (I2C/SCCB)**
   - Verifique conexões físicas da câmera
   - Confirme se a placa tem PSRAM
   - Tente reiniciar o ESP32
   - Verifique se os pinos não estão sendo usados por outros componentes
   - O código agora inclui retry automático (3 tentativas)

6. **Guru Meditation Error (Core panic)**
   - Geralmente causado por conflitos de pinos
   - Verifique se os pinos dos motores não conflitam com a câmera
   - Use configuração conservadora (QVGA) inicialmente
   - Reduza o número de buffers de frame (fb_count = 1)
   - O código agora detecta conflitos automaticamente

## 📊 Configurações de Qualidade

### Resolução e Qualidade
```cpp
config.frame_size = FRAMESIZE_VGA;   // 640x480
config.jpeg_quality = 12;            // 0-63 (menor = melhor)
```

**Vantagens da resolução VGA (640x480):**
- ✅ **Performance**: Menor uso de CPU e memória
- ✅ **Streaming**: Melhor taxa de quadros (FPS)
- ✅ **Rede**: Menor largura de banda necessária
- ✅ **Estabilidade**: Menos problemas de buffer overflow
- ✅ **Qualidade**: Ainda excelente para controle remoto


## 🔄 Fluxo de Funcionamento

### 1. Inicialização
1. ESP32 inicia e configura câmera
2. Configura pinos dos motores
3. Conecta ao WiFi
4. Inicia servidor de streaming HTTP
5. Conecta ao WebSocket do servidor Node.js

### 2. Registro no Servidor
1. ESP32 envia `register_car` com ID e URL de streaming
2. Servidor confirma registro
3. ESP32 inicia envio periódico de status

### 3. Controle Remoto
1. Usuário acessa interface web no servidor
2. Seleciona carro disponível
3. Envia comandos via WebSocket
4. Servidor repassa comandos para ESP32
5. ESP32 executa comandos nos motores
6. ESP32 envia status de volta

### 4. Streaming de Vídeo
1. ESP32 captura vídeo da câmera
2. Serve stream MJPEG na porta 81
3. Interface web exibe vídeo em tempo real

## 🔄 Atualizações e Melhorias

### Próximas Funcionalidades
- [x] Controle de direção via WebSocket
- [x] Telemetria de motores
- [ ] Telemetria de sensores (ultrassom, giroscópio)
- [ ] Gravação de vídeo local
- [ ] Interface de configuração web
- [ ] Sistema de logs persistente
- [ ] Controle de velocidade variável
- [ ] Sistema de segurança (parada automática)

## 📝 Logs e Debug

### Serial Output
```
WiFi connecting...
WiFi connected
Camera Ready! Use 'http://192.168.1.100' to connect
✅ Conectado ao servidor WebSocket!
📡 Registro enviado: {"type":"register_car","carId":"carro-esp32-01","streamUrl":"http://192.168.1.100:81/stream"}
```

## 👥 Contribuição

Este projeto faz parte do RaceCar 2025 da UENP. Para contribuições:
1. Faça fork do projeto
2. Crie uma branch para sua feature
3. Commit suas mudanças
4. Abra um Pull Request

## 📄 Licença

Projeto desenvolvido para fins educacionais na UENP - Universidade Estadual do Norte do Paraná.

---

**Desenvolvido por**: Ricardo G. Coelho - UENP  
**Data**: 2025  
**Versão**: 1.0
