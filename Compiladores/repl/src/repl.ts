import * as readline from 'readline'

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  prompt: '>>> ',
})

const variables: Record<string, number> = {}

function evaluate(expression: string): number {
  const replaced = expression.replace(/[a-zA-Z_][a-zA-Z0-9_]*/g, (name) => {
    if (variables.hasOwnProperty(name)) {
      return variables[name].toString()
    } else {
      throw new Error(`Variável "${name}" não definida.`)
    }
  })

  try {
    if (!/^[0-9+\-*/().\s]+$/.test(replaced)) {
      throw new Error("Expressão inválida")
    }

    return Function(`"use strict"; return (${replaced})`)()
  } catch (err) {
    throw new Error("Erro ao avaliar a expressão.")
  }
}

console.log('REPL - Digite expressões matemáticas ou declare variáveis.')
rl.prompt()

rl.on('line', (line: string) => {
  const input = line.trim()

  if (input === '') {
    rl.prompt()
    return
  }

  try {
    if (/^[a-zA-Z_][a-zA-Z0-9_]*\s*=\s*.+$/.test(input)) {
      const [varName, expr] = input.split('=').map((s: string) => s.trim())
      const value = evaluate(expr)
      variables[varName] = value
      console.log(`${varName} = ${value}`)
    } else if (/^[a-zA-Z_][a-zA-Z0-9_]*$/.test(input)) {
      if (variables.hasOwnProperty(input)) {
        console.log(`${input} = ${variables[input]}`)
      } else {
        console.log(`Variável "${input}" não definida.`)
      }
    } else {
      const result = evaluate(input)
      console.log(result)
    }
  } catch (e: any) {
    console.log(`Erro: ${e.message}`)
  }

  rl.prompt()
})
