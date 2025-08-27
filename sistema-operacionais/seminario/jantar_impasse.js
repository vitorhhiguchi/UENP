const { Semaphore, Philosopher } = require('./helper.js');

const NUM_PHILOSOPHERS = 5;
const EAT_TIMES = 3; // Cada filósofo tentará comer 3 vezes

class ImpassePhilosopher extends Philosopher {
    async run() {
        for (let i = 0; i < EAT_TIMES; i++) { // Loop limitado
            await this.think();

            this.state = 'HUNGRY';
            this.log('está com fome e vai pegar o palito da direita...');
            await this.rightChopstick.acquire();
            this.log('pegou o palito da direita.');

            this.log('vai tentar pegar o palito da esquerda...');
            await this.leftChopstick.acquire();
            this.log('pegou o palito da esquerda!');

            await this.eat();

            this.rightChopstick.release();
            this.log('devolveu o palito da direita.');
            this.leftChopstick.release();
            this.log('devolveu o palito da esquerda.');
        }
        this.log('Terminou de jantar e agora vai apenas meditar.');
    }
}

async function main() {
    console.log(`--- Cenário com Risco de Impasse (Cada um come ${EAT_TIMES} vezes) ---`);

    const chopsticks = Array.from({ length: NUM_PHILOSOPHERS }, () => new Semaphore(1));
    const philosophers = [];

    for (let i = 0; i < NUM_PHILOSOPHERS; i++) {
        const leftChopstick = chopsticks[i];
        const rightChopstick = chopsticks[(i + 1) % NUM_PHILOSOPHERS];
        philosophers.push(new ImpassePhilosopher(i, leftChopstick, rightChopstick));
    }

    // Espera todos os filósofos terminarem (ou travarem)
    try {
        const philosopherPromises = philosophers.map(p => p.run());
        await Promise.all(philosopherPromises);
        console.log('\nTodos os filósofos terminaram de comer sem impasse!');
    } catch (error) {
        console.error('Ocorreu um erro:', error);
    }
}

main();

/* 
O que Esperar: O programa vai rodar por um tempo, com alguns 
filósofos conseguindo comer. Eventualmente 
(pode demorar um pouco ou ser rápido), 
todos eles pegarão o palito da direita e ficarão presos 
tentando pegar o da esquerda. A saída no terminal vai parar e, 
após 5 segundos, a mensagem "!!! IMPASSE DETECTADO !!!" aparecerá.

Principal Problema: Deadlock. A estratégia de "pegar direita, 
depois esquerda" cria uma dependência circular, que é uma das 
condições essenciais para o impasse.
*/