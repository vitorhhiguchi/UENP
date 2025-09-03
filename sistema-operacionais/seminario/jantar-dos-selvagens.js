// savage-dinner.js
const { Worker, isMainThread, parentPort, workerData } = require('worker_threads');
const { performance } = require('perf_hooks');

const NUM_SELVAGENS = 5;
const PORCOES_NO_CALDEIRAO = 10;

// --- Recursos Compartilhados ---
const sharedBuffer = new SharedArrayBuffer(4 * 4);
const porcoes = new Int32Array(sharedBuffer, 0, 1);
const mcaldMutex = new Int32Array(sharedBuffer, 4, 1);
const caldVazioSem = new Int32Array(sharedBuffer, 8, 1);
const caldCheioSem = new Int32Array(sharedBuffer, 12, 1);

// --- Funções de Sincronização (reutilizadas) ---
function mutexLock(mutex) {
    while (Atomics.compareExchange(mutex, 0, 0, 1) !== 0) {
        Atomics.wait(mutex, 0, 1);
    }
}
function mutexUnlock(mutex) {
    Atomics.store(mutex, 0, 0);
    Atomics.notify(mutex, 0, 1);
}
function semWait(semaphore) {
    Atomics.sub(semaphore, 0, 1);
    while (Atomics.load(semaphore, 0) < 0) {
        Atomics.wait(semaphore, 0, Atomics.load(semaphore, 0));
    }
}
function semPost(semaphore) {
    Atomics.add(semaphore, 0, 1);
    Atomics.notify(semaphore, 0, 1);
}

// --- Lógica das Threads ---
function cozinheiro() {
    while (true) {
        console.log("Cozinheiro está dormindo...");
        semWait(caldVazioSem);

        console.log("Cozinheiro acordou! Enchendo o caldeirão...");
        mutexLock(mcaldMutex); // Cozinheiro também precisa de lock para encher
        Atomics.store(porcoes, 0, PORCOES_NO_CALDEIRAO);
        mutexUnlock(mcaldMutex);

        semPost(caldCheioSem);
    }
}

function selvagem(id) {
    while (true) {
        console.log(`Selvagem ${id} está com fome.`);
        mutexLock(mcaldMutex);

        if (Atomics.load(porcoes, 0) === 0) {
            console.log(`Selvagem ${id}: Caldeirão vazio! Acordando o cozinheiro.`);
            semPost(caldVazioSem);
            
            // CORREÇÃO DO DEADLOCK: Destravar o mutex ANTES de esperar
            mutexUnlock(mcaldMutex);
            
            semWait(caldCheioSem); // Espera o caldeirão encher
            
            // Re-adquire o lock para se servir
            mutexLock(mcaldMutex);
        }

        Atomics.sub(porcoes, 0, 1);
        const restantes = Atomics.load(porcoes, 0);
        console.log(`  Selvagem ${id} se serviu. Restam: ${restantes}`);
        
        mutexUnlock(mcaldMutex);

        console.log(`  Selvagem ${id} está comendo.`);
        const delay = Math.random() * 3000 + 1000;
        const start = performance.now();
        while(performance.now() - start < delay);
    }
}

if (isMainThread) {
    Atomics.store(porcoes, 0, PORCOES_NO_CALDEIRAO); // Começa cheio
    Atomics.store(mcaldMutex, 0, 0);
    Atomics.store(caldVazioSem, 0, 0);
    Atomics.store(caldCheioSem, 0, 0);

    new Worker(__filename, { workerData: { type: 'cozinheiro' } });
    for (let i = 0; i < NUM_SELVAGENS; i++) {
        new Worker(__filename, { workerData: { type: 'selvagem', id: i + 1 } });
    }
} else {
    const { type, id } = workerData;
    if (type === 'selvagem') selvagem(id);
    else if (type === 'cozinheiro') cozinheiro();
}