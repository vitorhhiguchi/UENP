fetch("https://pokeapi.co/api/v2/type/fire")
    .then(res => res.json())
    .then(fire=> console.log(fire.pokemon.map(p => p.pokemon.name)))

    