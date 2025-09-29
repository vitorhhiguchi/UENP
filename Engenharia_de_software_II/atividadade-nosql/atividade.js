// Classe para representar o endereço de entrega
class Endereco {
    constructor(rua, numero, cidade, estado, cep) {
        this.rua = rua;
        this.numero = numero;
        this.cidade = cidade;
        this.estado = estado;
        this.cep = cep;
    }
}

// Classe para representar os dados do cliente
class Cliente {
    constructor(nome, email, telefone, enderecoEntrega) {
        this.nome = nome;
        this.email = email;
        this.telefone = telefone;
        this.endereco_entrega = enderecoEntrega; // O objeto da classe Endereco virá aqui
    }
}

// Classe para representar cada item dentro de um pedido
class ItemPedido {
    constructor(produtoId, nomeProduto, quantidade, precoUnitario) {
        this.produto_id = produtoId; // ID de referência ao produto na coleção 'produtos'
        this.nome_produto = nomeProduto;
        this.quantidade = quantidade;
        this.preco_unitario = precoUnitario;
    }
}

// Classe principal que representa o Pedido completo
class Pedido {
    constructor(codigoPedido, cliente, itens, metodoPagamento) {
        // O _id é geralmente gerenciado pelo banco de dados, então o inicializamos como null
        this._id = null; 
        this.codigo_pedido = codigoPedido;
        this.data_pedido = new Date(); // Define a data e hora atual no momento da criação
        this.status = "Pendente"; // Status inicial padrão
        this.cliente = cliente; // Objeto da classe Cliente
        this.itens = itens; // Array de objetos da classe ItemPedido
        this.metodo_pagamento = metodoPagamento;
        this.valor_total = this.calcularValorTotal();
    }

    /**
     * Método para calcular o total do pedido com base nos itens.
     * @returns {number} O valor total do pedido.
     */
    calcularValorTotal() {
        const total = this.itens.reduce((soma, item) => {
            return soma + (item.quantidade * item.preco_unitario);
        }, 0);
        
        // Arredonda para 2 casas decimais
        return parseFloat(total.toFixed(2));
    }
}