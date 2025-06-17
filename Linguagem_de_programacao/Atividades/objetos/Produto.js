function Produto(nome, preco, estoque) {
    this.nome = nome;
    this.preco = preco;
    this.estoque = estoque;
    this.disponivel = estoque > 0;

    this.vender = function(quantidade) {
        if (this.estoque >= quantidade) {
            this.estoque -= quantidade;
            console.log(`${quantidade} unidade(s) de '${this.nome}' vendida(s).`);
            this.disponivel = this.estoque > 0; 
        } else {
            console.log(`Estoque insuficiente para '${this.nome}'.`);
        }
    };
}


const produto1 = new Produto("Notebook Gamer", 4500, 10);
const produto2 = new Produto("Mouse sem Fio", 150, 30);
const produto3 = new Produto("Teclado Mecânico", 350, 0);

console.log(produto1.nome); // Saída: Notebook Gamer
console.log(produto2.preco); // Saída: 150
console.log(produto3.disponivel); // Saída: false

produto1.vender(2); // Saída: 2 unidade(s) de 'Notebook Gamer' vendida(s).
console.log(produto1.estoque); // Saída: 8