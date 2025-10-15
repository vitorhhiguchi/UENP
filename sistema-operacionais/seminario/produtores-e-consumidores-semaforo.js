// Simulação de Semáforos e Mutex para fins didáticos
class Semaphore {
    constructor(initialCount = 1) {
        this.count = initialCount;
        this.waitQueue = [];
    }

    // Operação down() ou wait()
    async down() {
        if (this.count > 0) {
            this.count--;
            return;
        }
        // Se não há recursos, espera em uma fila
        return new Promise(resolve => this.waitQueue.push(resolve));
    }

    // Operação up() ou signal()
    up() {
        this.count++;
        if (this.waitQueue.length > 0) {
            // Acorda a tarefa mais antiga na fila
            const next = this.waitQueue.shift();
            this.count--; // O recurso é imediatamente consumido pela tarefa acordada
            next();
        }
    }
}

// --- Lógica do Problema ---
const BUFFER_SIZE = 5;
const buffer = [];

// Semáforos da solução
const mutex = new Semaphore(1);       // Para exclusão mútua, inicializado com 1
const item = new Semaphore(0);        // Conta itens no buffer, inicializado com 0
const vaga = new Semaphore(BUFFER_SIZE); // Conta vagas no buffer, inicializado com N

// Função auxiliar para criar uma pausa aleatória
const randomDelay = () => new Promise(res => setTimeout(res, Math.random() * 1000));

// Lógica do Produtor
async function produtor(id) {
    for (let i = 0; i < 5; i++) {
        const novoItem = `Item ${i} do Produtor ${id}`;
        console.log(`Produtor ${id} produziu: ${novoItem}`);

        await vaga.down();      // Espera por uma vaga
        await mutex.down();     // Entra na região crítica
        
        buffer.push(novoItem);
        console.log(`%cProdutor ${id} depositou. Buffer: [${buffer.join(', ')}]`, 'color: green');
        
        await mutex.up();       // Sai da região crítica
        item.up();              // Sinaliza que há um novo item
        
        await randomDelay();
    }
}

// Lógica do Consumidor
async function consumidor(id) {
    for (let i = 0; i < 5; i++) {
        await item.down();      // Espera por um item
        await mutex.down();     // Entra na região crítica
        
        const itemConsumido = buffer.shift();
        console.log(`%cConsumidor ${id} consumiu: ${itemConsumido}. Buffer: [${buffer.join(', ')}]`, 'color: red');
        
        await mutex.up();       // Sai da região crítica
        vaga.up();              // Sinaliza que há uma nova vaga

        await randomDelay();
    }
}

// Inicia a simulação
console.log("Iniciando simulação de Produtor/Consumidor com Semáforos...");
produtor(1);
consumidor(1);
produtor(2);
consumidor(2);