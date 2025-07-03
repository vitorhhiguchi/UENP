function processar(num1, num2, callback) {
    const resultado = callback(num1, num2);
    console.log(resultado);
}

function multiplicar(a, b) {
    return a * b;
}

function divisao(a, b) {
    return a / b;
}

function subtracao(a ,b) {
    return a - b;
}

function soma(a, b) {
    return a + b;
}

processar(3, 4, multiplicar);
processar(3, 4, soma);