// producers-consumers.js
const { Worker, isMainThread, parentPort, workerData } = require('worker_threads');
const { performance } = require('perf_hooks');

const BUFFER_SIZE = 5;
const NUM_PRODUTORES = 2;
const NUM_CONSUMIDORES = 2;

// --- Recursos Compartilhados ---
// Usamos SharedArrayBuffer para permitir que a memória seja compartilhada entre as threads.
const sharedBuffer = new SharedArrayBuffer(BUFFER_SIZE * 4 + 4 * 4); // buffer + in/out + semáforos
const buffer = new Int32Array(sharedBuffer, 0, BUFFER_SIZE);
const inIndex = new Int32Array(sharedBuffer, BUFFER_SIZE * 4, 1);
const outIndex = new Int32Array(sharedBuffer, BUFFER_SIZE * 4 + 4, 1);
const itemSem = new Int32Array(sharedBuffer, BUFFER_SIZE * 4 + 8, 1);
const vagaSem = new Int32Array(sharedBuffer, BUFFER_SIZE * 4 + 12, 1);

// --- Funções Auxiliares de Sincronização ---
function semWait(semaphore) {
    while (true) {
        let count = Atomics.load(semaphore, 0);
        if (count > 0) {
            // Tenta decrementar de forma atômica
            if (Atomics.compareExchange(semaphore, 0, count, count - 1) === count) {
                return; // Sucesso
            }
        }
        Atomics.wait(semaphore, 0, 0, 1000); // Espera se for 0
    }
}

function semPost(semaphore) {
    Atomics.add(semaphore, 0, 1);
    Atomics.notify(semaphore, 0, 1); // Acorda uma thread que esteja esperando
}

// --- Lógica das Threads ---
function produtor(id) {
    while (true) {
        const item_produzido = Math.floor(Math.random() * 100);
        console.log(`Produtor ${id} produziu ${item_produzido}`);

        semWait(vagaSem); // Espera por uma vaga

        // Seção Crítica (não precisamos de mutex aqui porque os semáforos já garantem a ordem)
        const index = Atomics.load(inIndex, 0);
        Atomics.store(buffer, index, item_produzido);
        Atomics.store(inIndex, 0, (index + 1) % BUFFER_SIZE);
        console.log(`Produtor ${id} depositou ${item_produzido} no buffer`);

        semPost(itemSem); // Sinaliza que há um novo item

        // Simula trabalho
        const delay = Math.random() * 2000 + 1000;
        const start = performance.now();
        while(performance.now() - start < delay);
    }
}

function consumidor(id) {
     while (true) {
        semWait(itemSem); // Espera por um item

        // Seção Crítica
        const index = Atomics.load(outIndex, 0);
        const item_consumido = Atomics.load(buffer, index);
        Atomics.store(outIndex, 0, (index + 1) % BUFFER_SIZE);
        console.log(`          Consumidor ${id} consumiu ${item_consumido}`);
        
        semPost(vagaSem); // Sinaliza que há uma nova vaga

        // Simula consumo
        console.log(`          Consumidor ${id} está processando ${item_consumido}`);
        const delay = Math.random() * 3000 + 1000;
        const start = performance.now();
        while(performance.now() - start < delay);
    }
}

// --- Ponto de Entrada Principal ---
if (isMainThread) {
    console.log("Iniciando simulação Produtor/Consumidor...");
    
    // Inicializa semáforos e índices
    Atomics.store(inIndex, 0, 0);
    Atomics.store(outIndex, 0, 0);
    Atomics.store(itemSem, 0, 0); // 0 itens no início
    Atomics.store(vagaSem, 0, BUFFER_SIZE); // N vagas no início

    // Cria as threads (workers)
    for (let i = 0; i < NUM_PRODUTORES; i++) {
        new Worker(__filename, { workerData: { type: 'produtor', id: i + 1 } });
    }
    for (let i = 0; i < NUM_CONSUMIDORES; i++) {
        new Worker(__filename, { workerData: { type: 'consumidor', id: i + 1 } });
    }
} else {
    // Código que executa dentro do worker
    const { type, id } = workerData;
    if (type === 'produtor') {
        produtor(id);
    } else if (type === 'consumidor') {
        consumidor(id);
    }
}