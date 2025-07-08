function clicar() {
    document.getElementById('botao').textContent = "Você clicou no botão";

    if(navigator.geolocation) {
        navigator.geolocation.getCurrentPosition(
            (posicao) => {
                const latitude = posicao.coords.latitude;
                alert("Sua latitude é: " + latitude);
            },
            (erro) => {
                alert("Erro ao obter localização: ", erro.message);
            }
        );
    } else {
        alert("Geolocalização não é suportada neste navegador.");
    }
}