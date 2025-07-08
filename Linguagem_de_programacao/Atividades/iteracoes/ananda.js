const alunos = ['Ana', 'Carlos', 'Joao', 'Ana', 'Carlos', 'Lucas'];

const presencas = new Map([
    ['Workshop JS', new Set(['Ana', 'Carlos', 'Joao'])],
    ['Workshop Python', new Set(['Carlos', 'Lucas'])],
    ['Workshop Java', new Set(['Joao', 'Ana'])],
]);

const alunosUnicos = [...new Set(alunos)];

const participacoes = new Map();

for (const aluno of alunosUnicos) {
    participacoes.set(aluno, new Set());

    for (const [workshop, participantes] of presencas) {
        if (participantes.has(aluno)) {
            participacoes.get(aluno).add(workshop);
        }
    }
}

for (const [aluno, workshops] of participacoes) {
  console.log(`${aluno}: ${[...workshops].join(', ')}`);
}