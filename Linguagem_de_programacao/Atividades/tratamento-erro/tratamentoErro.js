function saudacao ( nome ) {
    console.log (" Oi , " + nome.toUpperCase() );
}

try {
    saudacao();
} catch(e) {
    console.log("Erro" + e.message);
}


