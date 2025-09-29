// Importando a biblioteca mongoose
const mongoose = require('mongoose');
const { Schema } = mongoose;

// 1. Schema para o Documento Embutido: Endereco
// Corresponde à classe Endereco
const enderecoSchema = new Schema({
    rua: { type: String, required: true },
    numero: { type: Number, required: true },
    cidade: { type: String, required: true },
    estado: { type: String, required: true, maxlength: 2 },
    cep: { type: String, required: true }
}, { _id: false }); // _id: false para não criar um Id para o sub-documento de endereço

// 2. Schema para o Documento Embutido: Cliente
// Corresponde à classe Cliente e contém o enderecoSchema
const clienteSchema = new Schema({
    nome: { type: String, required: true },
    email: { type: String, required: true },
    telefone: String,
    endereco_entrega: enderecoSchema // <-- MAPEAMENTO DE OBJETO EMBUTIDO
}, { _id: false });

// 3. Schema para os Documentos no Array de Itens
// Corresponde à classe ItemPedido
const itemPedidoSchema = new Schema({
    produto_id: { type: Schema.Types.ObjectId, ref: 'Produto', required: true },
    nome_produto: { type: String, required: true },
    quantidade: { type: Number, required: true, min: 1 },
    preco_unitario: { type: Number, required: true }
}, { _id: false });

// 4. Schema Principal: Pedido
// Corresponde à classe Pedido e une todos os outros schemas
const pedidoSchema = new Schema({
    codigo_pedido: { type: String, required: true, unique: true },
    data_pedido: { type: Date, default: Date.now },
    status: { type: String, required: true, default: 'Pendente' },
    cliente: clienteSchema, // <-- MAPEAMENTO DE OBJETO EMBUTIDO
    itens: [itemPedidoSchema], // <-- MAPEAMENTO DE ARRAY DE OBJETOS
    valor_total: { type: Number, required: true },
    metodo_pagamento: String,
    ultima_atualizacao: { type: Date, default: Date.now }
});

// 5. Criando o Model
// O Mongoose vai criar (ou usar) uma coleção chamada "pedidos" (plural e minúsculo)
const PedidoModel = mongoose.model('Pedido', pedidoSchema);

// Exportamos o modelo para ser usado em outras partes da aplicação
module.exports = PedidoModel;