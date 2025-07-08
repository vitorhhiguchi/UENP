 let worker;

function startWorker() {
    worker = new Worker('worker.js');
    worker.onmessage = function(event) {
        document.getElementById('resultado').textContent = 'Contagem finalizada: ' + event.data;
    };

    worker.postMessage('iniciar');
}