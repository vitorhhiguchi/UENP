onmessage = function(event) {
  if (event.data === 'iniciar') {
    let contador = 0;
    for (let i = 1; i <= 1_000_000_000; i++) {
      contador = i;
    }

    postMessage(contador);
  }
};