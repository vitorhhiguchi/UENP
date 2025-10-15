// Simulação de Semáforos e Mutex para fins didáticos
class Semaphore {
    constructor(initialCount = 1) {
        this.count = initialCount;
        this.waitQueue = [];
    }
    async down() {
        if (this.count > 0) {
            this.count--;
            return;
        }
        return new Promise(resolve => this.waitQueue.push(resolve));
    }
    up() {
        this.count++;
        if (this.waitQueue.length > 0) {
            const next = this.waitQueue.shift();
            this.count--;
            next();
        }
    }
}
class Mutex extends Semaphore {
    constructor() { super(1); }
    lock() { return this.down(); }
    unlock() { this.up(); }
}

// --- Lógica do Problema ---
const PORCOES_TOTAIS = 5;
let porcoes = 0; // O caldeirão começa vazio

// Semáforos e Mutex da solução
const mcald = new Mutex();
const cald_vazio = new Semaphore(0);
const cald_cheio = new Semaphore(0);

const randomDelay = () => new Promise(res => setTimeout(res, Math.random() * 1000 + 200));

// Lógica do Cozinheiro
async function cozinheiro() {
    while (true) {
        console.log("Cozinheiro está dormindo... 😴");
        await cald_vazio.down(); // Espera ser acordado
        
        console.log("%cCozinheiro foi acordado e está cozinhando...", 'color: fuchsia; font-weight: bold');
        await randomDelay();
        porcoes = PORCOES_TOTAIS;
        console.log(`%cCozinheiro encheu o caldeirão com ${porcoes} porções.`, 'color: fuchsia; font-weight: bold');

        cald_cheio.up(); // Avisa o selvagem que a comida está pronta
    }
}

// Lógica do Selvagem
async function selvagem(id) {
    while (true) {
        console.log(`Selvagem ${id} está com fome e vai ao caldeirão.`);
        
        await mcald.lock();
        
        if (porcoes === 0) {
            console.log(`%cSelvagem ${id} encontrou o caldeirão VAZIO! Acordando o cozinheiro.`, 'color: orange');
            cald_vazio.up(); // Acorda o cozinheiro
            await cald_cheio.down(); // Espera a comida ficar pronta
            console.log(`%cSelvagem ${id} viu que o caldeirão está cheio e vai se servir.`, 'color: orange');
        }

        porcoes--;
        console.log(`Selvagem ${id} se serviu. Restam ${porcoes} porções.`);

        mcald.unlock();

        console.log(`Selvagem ${id} está comendo. 😋`);
        await randomDelay(); // Simula o tempo de comer
    }
}

// Inicia a simulação
console.log("Iniciando simulação do Jantar dos Selvagens...");
cozinheiro(); 

// Inicia vários selvagens com um pequeno atraso entre eles
setTimeout(() => selvagem(1), 500);
setTimeout(() => selvagem(2), 1000);
setTimeout(() => selvagem(3), 1500);