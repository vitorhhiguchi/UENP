const cachorro = {
    nome: "Azwinton",
    idade: 4,
    raca: "Pastor Alemão",
    cor: "Marrom",
    latido: function() {
        return "Au au!";
    },
    caracteristicas: function() {
        return `Nome: ${this.nome}, Idade: ${this.idade} anos, 
        Raça: ${this.raca}, Cor: ${this.cor}`;
    }
}