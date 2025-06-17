function criarVerificadorSenha(senhaCorreta) {
  return function(tentativa) {
    if (tentativa === senhaCorreta) {
      return "Acesso permitido";
    }
    return "Senha incorreta";
  };
}

const verificar = criarVerificadorSenha("abc123");

console.log(verificar("senha"));      // Imprime: "Senha incorreta"
console.log(verificar("abc123"));     // Imprime: "Acesso permitido"

const verificarOutraSenha = criarVerificadorSenha("senhaForte!@#");
console.log(verificarOutraSenha("abc123")); // Imprime: "Senha incorreta"
console.log(verificarOutraSenha("senhaForte!@#")); // Imprime: "Acesso permitido"