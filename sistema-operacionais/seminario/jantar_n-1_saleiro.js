const { Semaphore, Philosopher } = require('./helper.js');

const NUM_PHILOSOPHERS = 5;
const EAT_TIMES = 3;

// A "mesa" tem N-1 lugares.
const table = new Semaphore(NUM_PHILOSOPHERS - 1);

class SmartPhilosopher extends Philosopher {
    async run() {
        for (let i = 0; i < EAT_TIMES; i++) { // Loop limitado
            await this.think();

            this.log('está com fome e vai tentar sentar à mesa...');
            await table.acquire();
            this.log('sentou-se à mesa.');

            this.log('vai pegar os palitos...');
            await this.rightChopstick.acquire();
            await this.leftChopstick.acquire();
            this.log('pegou os dois palitos.');

            await this.eat();

            this.rightChopstick.release();
            this.leftChopstick.release();
            this.log('devolveu os palitos.');

            table.release();
            this.log('levantou-se da mesa.');
        }
        this.log('Terminou de jantar e agora vai apenas meditar.');
    }
}


async function main() {
    console.log(`--- Cenário com "N-1 Saleiros" (Cada um come ${EAT_TIMES} vezes) ---`);
    const chopsticks = Array.from({ length: NUM_PHILOSOPHERS }, () => new Semaphore(1));
    const philosophers = [];

    for (let i = 0; i < NUM_PHILOSOPHERS; i++) {
        const leftChopstick = chopsticks[i];
        const rightChopstick = chopsticks[(i + 1) % NUM_PHILOSOPHERS];
        philosophers.push(new SmartPhilosopher(i, leftChopstick, rightChopstick));
    }

    const philosopherPromises = philosophers.map(p => p.run());
    await Promise.all(philosopherPromises);
    
    console.log('\nTodos os filósofos terminaram de comer!');
    philosophers.forEach(p => console.log(`- Filósofo ${p.id} comeu ${p.eatCount} vezes.`));
}

main();