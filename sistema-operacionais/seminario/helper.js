// Função para simular o tempo (pensando ou comendo)
const delay = (ms) => new Promise(resolve => setTimeout(resolve, ms));

// Implementação de um Semáforo de contagem em JavaScript
class Semaphore {
    constructor(count) {
        this.count = count; // Nº de permissões (1 para mutex, N-1 para a mesa)
        this.queue = [];    // Fila de espera
    }

    // Equivalente ao "down()" ou "wait()"
    async acquire() {
        if (this.count > 0) {
            this.count--;
            return;
        }
        // Se não há permissões, espera na fila
        return new Promise(resolve => this.queue.push(resolve));
    }

    // Equivalente ao "up()" ou "signal()"
    release() {
        this.count++;
        // Se houver alguém na fila, libera o primeiro
        if (this.queue.length > 0) {
            const resolve = this.queue.shift();
            this.count--;
            resolve();
        }
    }
}

// Classe que representa um Filósofo
class Philosopher {
    constructor(id, leftChopstick, rightChopstick) {
        this.id = id;
        this.leftChopstick = leftChopstick;
        this.rightChopstick = rightChopstick;
        this.state = 'THINKING';
        this.eatCount = 0;
    }

    log(message) {
        console.log(`Filósofo ${this.id}: ${message}`);
    }

    async think() {
        this.state = 'THINKING';
        this.log('está meditando...');
        await delay(Math.random() * 3000 + 1000); // Pensa por 1 a 4 segundos
    }

    async eat() {
        this.state = 'EATING';
        this.eatCount++;
        this.log(`está comendo pela ${this.eatCount}ª vez.`);
        await delay(Math.random() * 2000 + 1000); // Come por 1 a 3 segundos
    }
}

// Exportamos as classes para usar nos outros arquivos
module.exports = { Semaphore, Philosopher, delay };