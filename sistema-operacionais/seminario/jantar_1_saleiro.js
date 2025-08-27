const { Semaphore, Philosopher } = require('./helper.js');

const NUM_PHILOSOPHERS = 5;
const EAT_TIMES = 3;

const waiter = new Semaphore(1); // O "saleiro"

class WaiterPhilosopher extends Philosopher {
    async run() {
        for (let i = 0; i < EAT_TIMES; i++) { // Loop limitado
            await this.think();
            
            this.log('está com fome e vai pedir permissão ao "garçom" (saleiro)...');
            await waiter.acquire();
            this.log('recebeu permissão!');

            this.log('vai pegar os palitos...');
            await this.rightChopstick.acquire();
            await this.leftChopstick.acquire();
            this.log('pegou os dois palitos.');

            waiter.release();
            this.log('liberou o "garçom" (saleiro).');

            await this.eat();

            this.rightChopstick.release();
            this.leftChopstick.release();
            this.log('devolveu os dois palitos.');
        }
        this.log('Terminou de jantar e agora vai apenas meditar.');
    }
}

async function main() {
    console.log(`--- Cenário com 1 "Saleiro" (Cada um come ${EAT_TIMES} vezes) ---`);
    const chopsticks = Array.from({ length: NUM_PHILOSOPHERS }, () => new Semaphore(1));
    const philosophers = [];

    for (let i = 0; i < NUM_PHILOSOPHERS; i++) {
        const leftChopstick = chopsticks[i];
        const rightChopstick = chopsticks[(i + 1) % NUM_PHILOSOPHERS];
        philosophers.push(new WaiterPhilosopher(i, leftChopstick, rightChopstick));
    }
    
    const philosopherPromises = philosophers.map(p => p.run());
    await Promise.all(philosopherPromises);

    console.log('\nTodos os filósofos terminaram de comer!');
    philosophers.forEach(p => console.log(`- Filósofo ${p.id} comeu ${p.eatCount} vezes.`));
}

main();

/* 
O que Esperar: O programa rodará indefinidamente sem travar. 
Observe atentamente a saída: você nunca verá dois filósofos comendo 
ao mesmo tempo. Um filósofo come, termina, e só então outro consegue pegar 
os palitos para comer.

Principal Problema: Baixa Concorrência. A solução é segura 
(sem impasse), mas é muito ineficiente. 
Ela serializa o acesso aos recursos, mesmo quando não haveria 
conflito (ex: filósofos 0 e 2 poderiam comer juntos, 
mas não conseguem).

*/