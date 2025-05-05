import express from 'express';
import cors from 'cors';

const app = express();
app.use(cors());
app.use(express.json());

const variables: Record<string, number> = {};

function evaluate(input: string): string {
  input = input.trim();

  if (input.includes('=')) {
    const [varName, expr] = input.split('=').map(s => s.trim());
    const value = evaluateExpression(expr);
    variables[varName] = value;
    return `${varName} = ${value}`;
  }

  if (variables[input] !== undefined) {
    return `${input} = ${variables[input]}`;
  }

  const value = evaluateExpression(input);
  return `${value}`;
}

function evaluateExpression(expr: string): number {
  const replacedExpr = expr.replace(/[a-zA-Z_]\w*/g, (name) => {
    if (variables[name] !== undefined) return variables[name].toString();
    throw new Error(`Variável '${name}' não definida`);
  });

  return Function(`"use strict"; return (${replacedExpr})`)();
}

app.post('/repl', (req, res) => {
  try {
    const result = evaluate(req.body.input);
    res.json({ result });
  } catch (err: any) {
    res.status(400).json({ error: err.message });
  }
});

app.listen(3001, () => {
  console.log('Servidor rodando em http://localhost:3001');
});
