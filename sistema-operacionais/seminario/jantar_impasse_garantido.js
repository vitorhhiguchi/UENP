// Esta versão é projetada para forçar o deadlock.

const { Semaphore, Philosopher, delay } = require('./helper.js');

const NUM_PHILOSOPHERS = 5;

class ImpasseGuaranteedPhilosopher extends Philosopher {
    async run() {
        // Roda apenas uma vez para demonstrar o impasse
        this.log('está meditando (sincronizando)...');
        await delay(10); // Pausa mínima para todos iniciarem

        this.state = 'HUNGRY';
        this.log('está com fome e vai pegar o palito da direita...');
        await this.rightChopstick.acquire();
        this.log('pegou o palito da direita.');

        // PAUSA CRÍTICA: Dá a chance para todos os outros filósofos
        // também pegarem seu primeiro palito antes de prosseguir.
        // É isso que força o cenário de impasse.
        this.log('pausando para sincronizar o impasse...');
        await delay(50); 

        this.log('vai tentar pegar o palito da esquerda...');
        await this.leftChopstick.acquire(); // <-- AQUI VAI TRAVAR!
        
        // O código nunca chegará neste ponto
        this.log('pegou o palito da esquerda! (Isso não deveria acontecer)');
        await this.eat();

        this.rightChopstick.release();
        this.leftChopstick.release();
        this.log('Terminou de jantar.');
    }
}

async function main() {
    console.log('--- Cenário com Impasse (Deadlock) Garantido ---');

    const chopsticks = Array.from({ length: NUM_PHILOSOPHERS }, () => new Semaphore(1));
    const philosophers = [];

    for (let i = 0; i < NUM_PHILOSOPHERS; i++) {
        const leftChopstick = chopsticks[i];
        const rightChopstick = chopsticks[(i + 1) % NUM_PHILOSOPHERS];
        philosophers.push(new ImpasseGuaranteedPhilosopher(i, leftChopstick, rightChopstick));
    }
    
    // Inicia todos os filósofos
    philosophers.forEach(p => p.run());

    // Adicionamos um timer para declarar o impasse e sair do programa.
    setTimeout(() => {
        console.error('\n================================================================');
        console.error('O PROGRAMA TRAVOU. IMPASSE CONFIRMADO!');
        console.error('Todos os filósofos pegaram o palito da direita e estão esperando eternamente pelo da esquerda.');
        console.error('================================================================');
        process.exit(1);
    }, 2000); // Espera 2 segundos para confirmar o travamento.
}

main();