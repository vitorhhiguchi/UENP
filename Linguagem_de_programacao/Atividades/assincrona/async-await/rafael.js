//Precisamos criar uma função assincrona, se não, não é possivel utilizar o 
// await

async function carregarDados() {
    const resposta = await fetch("https://pokeapi.co/api/v2/type/fire");
    const dados = await resposta.json();
    const nomes = dados.pokemon.map(p => p.pokemon.name);
    console.log(nomes);
}

carregarDados();