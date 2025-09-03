// readers-writers.js
const { Worker, isMainThread, parentPort, workerData } = require('worker_threads');
const { performance } = require('perf_hooks');

const NUM_LEITORES = 5;
const NUM_ESCRITORES = 2;

// --- Recursos Compartilhados ---
const sharedBuffer = new SharedArrayBuffer(4 * 4); // dado + num_leitores + 2 mutexes
const dadoCompartilhado = new Int32Array(sharedBuffer, 0, 1);
const numLeitores = new Int32Array(sharedBuffer, 4, 1);
const mareaMutex = new Int32Array(sharedBuffer, 8, 1); // 0 = livre, 1 = ocupado
const mcontMutex = new Int32Array(sharedBuffer, 12, 1); // 0 = livre, 1 = ocupado

// --- Funções Auxiliares de Sincronização ---
function mutexLock(mutex) {
    // Tenta obter o lock (mudar de 0 para 1). Se falhar, espera.
    while (Atomics.compareExchange(mutex, 0, 0, 1) !== 0) {
        Atomics.wait(mutex, 0, 1);
    }
}

function mutexUnlock(mutex) {
    Atomics.store(mutex, 0, 0); // Libera o lock
    Atomics.notify(mutex, 0, 1); // Acorda uma thread que esteja esperando
}

// --- Lógica das Threads ---
function leitor(id) {
    while (true) {
        mutexLock(mcontMutex);
        Atomics.add(numLeitores, 0, 1);
        if (Atomics.load(numLeitores, 0) === 1) {
            console.log(`Leitor ${id} é o primeiro, bloqueando escritores.`);
            mutexLock(mareaMutex);
        }
        mutexUnlock(mcontMutex);

        const dado = Atomics.load(dadoCompartilhado, 0);
        const leitoresAtivos = Atomics.load(numLeitores, 0);
        console.log(`Leitor ${id} leu o dado: ${dado} (leitores ativos: ${leitoresAtivos})`);

        mutexLock(mcontMutex);
        Atomics.sub(numLeitores, 0, 1);
        if (Atomics.load(numLeitores, 0) === 0) {
            console.log(`Leitor ${id} é o último, liberando para escritores.`);
            mutexUnlock(mareaMutex);
        }
        mutexUnlock(mcontMutex);
        
        const delay = Math.random() * 2000 + 500;
        const start = performance.now();
        while(performance.now() - start < delay);
    }
}

function escritor(id) {
    while (true) {
        console.log(`  Escritor ${id} quer escrever.`);
        mutexLock(mareaMutex);

        const novoDado = Math.floor(Math.random() * 100);
        Atomics.store(dadoCompartilhado, 0, novoDado);
        console.log(`  >>> Escritor ${id} escreveu o dado: ${novoDado}`);
        
        mutexUnlock(mareaMutex);
        
        const delay = Math.random() * 4000 + 1000;
        const start = performance.now();
        while(performance.now() - start < delay);
    }
}

if (isMainThread) {
    // Inicia os mutexes (0 = livre)
    Atomics.store(mareaMutex, 0, 0);
    Atomics.store(mcontMutex, 0, 0);
    
    for (let i = 0; i < NUM_ESCRITORES; i++) {
        new Worker(__filename, { workerData: { type: 'escritor', id: i + 1 } });
    }
    for (let i = 0; i < NUM_LEITORES; i++) {
        new Worker(__filename, { workerData: { type: 'leitor', id: i + 1 } });
    }
} else {
    const { type, id } = workerData;
    if (type === 'leitor') leitor(id);
    else if (type === 'escritor') escritor(id);
}