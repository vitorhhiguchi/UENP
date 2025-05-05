"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || (function () {
    var ownKeys = function(o) {
        ownKeys = Object.getOwnPropertyNames || function (o) {
            var ar = [];
            for (var k in o) if (Object.prototype.hasOwnProperty.call(o, k)) ar[ar.length] = k;
            return ar;
        };
        return ownKeys(o);
    };
    return function (mod) {
        if (mod && mod.__esModule) return mod;
        var result = {};
        if (mod != null) for (var k = ownKeys(mod), i = 0; i < k.length; i++) if (k[i] !== "default") __createBinding(result, mod, k[i]);
        __setModuleDefault(result, mod);
        return result;
    };
})();
Object.defineProperty(exports, "__esModule", { value: true });
const readline = __importStar(require("readline"));
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
    prompt: '>>> ',
});
const variables = {};
function evaluate(expression) {
    const replaced = expression.replace(/[a-zA-Z_][a-zA-Z0-9_]*/g, (name) => {
        if (variables.hasOwnProperty(name)) {
            return variables[name].toString();
        }
        else {
            throw new Error(`Variável "${name}" não definida.`);
        }
    });
    try {
        if (!/^[0-9+\-*/().\s]+$/.test(replaced)) {
            throw new Error("Expressão inválida");
        }
        return Function(`"use strict"; return (${replaced})`)();
    }
    catch (err) {
        throw new Error("Erro ao avaliar a expressão.");
    }
}
console.log('REPL - Digite expressões matemáticas ou declare variáveis.');
rl.prompt();
rl.on('line', (line) => {
    const input = line.trim();
    if (input === '') {
        rl.prompt();
        return;
    }
    try {
        if (/^[a-zA-Z_][a-zA-Z0-9_]*\s*=\s*.+$/.test(input)) {
            const [varName, expr] = input.split('=').map((s) => s.trim());
            const value = evaluate(expr);
            variables[varName] = value;
            console.log(`${varName} = ${value}`);
        }
        else if (/^[a-zA-Z_][a-zA-Z0-9_]*$/.test(input)) {
            if (variables.hasOwnProperty(input)) {
                console.log(`${input} = ${variables[input]}`);
            }
            else {
                console.log(`Variável "${input}" não definida.`);
            }
        }
        else {
            const result = evaluate(input);
            console.log(result);
        }
    }
    catch (e) {
        console.log(`Erro: ${e.message}`);
    }
    rl.prompt();
});
