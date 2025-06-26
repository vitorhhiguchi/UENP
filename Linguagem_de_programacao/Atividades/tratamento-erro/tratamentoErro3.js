
function dividir (a , b ) {
    if(b === 0) throw new Error("Não é possivel dividir por zero")
    return a/b;
}

console.log ( dividir (10 , 2) ); // deve funcionar
console.log ( dividir (5 , 0) ); // deve l a n a r erro
