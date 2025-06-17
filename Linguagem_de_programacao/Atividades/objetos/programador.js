const desenvolvedor = {
    nome: "Vitor",
    senioridade: "Pleno",
    disponivel: true,

    tecnologias: {
        linguagem_principal: "JavaScript",
        framework_frontend: "React",
        framework_backend: "Node.js",
        banco_de_dados: "PostgreSQL"
    },
    apresentar: function() {
        console.log(`Olá, eu sou ${this.nome}.`);
        console.log(`Minha linguagem principal é ${this.tecnologias.linguagem_principal}.`);
    }
};

console.log(desenvolvedor.apresentar());
console.log(desenvolvedor.tecnologias.framework_frontend);

desenvolvedor.apresentar();