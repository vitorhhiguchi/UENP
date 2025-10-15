// Simulação de Mutex para fins didáticos
class Mutex {
    constructor() {
        this.locked = false;
        this.waitQueue = [];
    }

    async lock() {
        if (!this.locked) {
            this.locked = true;
            return;
        }
        return new Promise(resolve => this.waitQueue.push(resolve));
    }

    unlock() {
        if (this.waitQueue.length > 0) {
            const next = this.waitQueue.shift();
            next();
        } else {
            this.locked = false;
        }
    }
}


// --- Lógica do Problema ---
let sharedResource = "Dados Iniciais";
let num_leitores = 0;

// Mutexes da solução
const mcont = new Mutex();  // Protege num_leitores
const marea = new Mutex();  // Protege o recurso compartilhado

const randomDelay = () => new Promise(res => setTimeout(res, Math.random() * 1500));

// Lógica do Leitor
async function leitor(id) {
    for(let i=0; i < 3; i++) {
        console.log(`Leitor ${id} quer ler.`);
        
        await mcont.lock();
        num_leitores++;
        if (num_leitores === 1) {
            await marea.lock(); // Primeiro leitor bloqueia para escritores
        }
        mcont.unlock();

        console.log(`%cLeitor ${id} está LENDO. Recurso: "${sharedResource}". Leitores ativos: ${num_leitores}`, 'color: blue');
        await randomDelay(); // Simula o tempo de leitura
        console.log(`%cLeitor ${id} terminou de ler.`, 'color: blue');

        await mcont.lock();
        num_leitores--;
        if (num_leitores === 0) {
            marea.unlock(); // Último leitor libera para escritores
        }
        mcont.unlock();

        await randomDelay();
    }
}

// Lógica do Escritor
async function escritor(id) {
     for(let i=0; i < 2; i++) {
        console.log(`Escritor ${id} quer escrever.`);
        
        await marea.lock(); // Pede acesso exclusivo

        console.log(`%cEscritor ${id} está ESCREVENDO...`, 'color: orange; font-weight: bold');
        await randomDelay(); // Simula o tempo de escrita
        sharedResource = `Modificado por Escritor ${id} às ${new Date().toLocaleTimeString()}`;
        console.log(`%cEscritor ${id} terminou de escrever. Recurso: "${sharedResource}"`, 'color: orange; font-weight: bold');

        marea.unlock();

        await randomDelay();
    }
}

// Inicia a simulação
console.log("Iniciando simulação de Leitores/Escritores com prioridade para leitores...");
leitor(1);
leitor(2);
escritor(1);
leitor(3);
escritor(2);
leitor(4);