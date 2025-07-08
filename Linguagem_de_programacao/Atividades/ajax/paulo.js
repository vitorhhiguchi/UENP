function gerarPiada() {
    fetch('https://api.chucknorris.io/jokes/random')
        .then(response => response.json())
        .then(data => {
            console.log(data.value)
            document.getElementById('piada').textContent = data.value;
        })
        .catch(error => console.log('Erro!', error));
}
