const fs = require('fs');
const path = require('path');
const { performance } = require('perf_hooks');
const process = require('process'); 


// Função para carregar especificações do autômato a partir de um arquivo JSON
function loadAutomatonSpecs(filePath) {
    const rawdata = fs.readFileSync(filePath);
    return JSON.parse(rawdata);
}

// Função para carregar entradas de teste a partir de um arquivo de texto
function loadTestCases(filePath) {
    const rawdata = fs.readFileSync(filePath, 'utf8');
    return rawdata.split('\n').filter(line => line.trim() !== '').map(line => {
        const [input, expected] = line.split(';');
        return { input, expected: parseInt(expected, 10) };
    });
}

// Classe para o Autômato Finito Determinístico (DFA)
class DFA {
    constructor(specs) {
        this.initialState = specs.initial;
        this.acceptStates = specs.final;
        this.transitions = this.buildTransitionTable(specs.transitions);
        this.currentState = this.initialState;
    }

    buildTransitionTable(transitions) {
        const table = {};
        transitions.forEach(transition => {
            if (!table[transition.from]) {
                table[transition.from] = {};
            }
            table[transition.from][transition.read] = transition.to;
        });
        return table;
    }

    reset() {
        this.currentState = this.initialState;
    }

    processSymbol(symbol) {
        if (this.transitions[this.currentState] && this.transitions[this.currentState][symbol] !== undefined) {
            this.currentState = this.transitions[this.currentState][symbol];
            return this.currentState;
        } else {
            return this.currentState = false;
        }
    }

    processString(inputString) {
        this.reset();
        for (let symbol of inputString) {
            if (!this.processSymbol(symbol)) {
                return false;
            }
        }
        return this.acceptStates.includes(parseInt(this.currentState));
    }
}

// Função para executar testes e salvar resultados no arquivo
function runTestsAndSaveResults(dfa, testCases, outputFilePath) {
    let results = 'input;expected;result;time\n\n'; // Cabeçalho do CSV

    testCases.forEach((testCase, index) => {
        const start = performance.now();
        const result = dfa.processString(testCase.input) ? 1 : 0;
        const end = performance.now();
        const timeTaken = (end - start).toFixed(3);

        results += `${testCase.input};${testCase.expected};${result};${timeTaken}\n`;
    });

    fs.writeFileSync(outputFilePath, results);
}

// Caminhos para os arquivos JSON e de testes
const automatonSpecsPath = process.argv[2]; 
const testCasesPath = process.argv[3];
const outputFilePath = process.argv[4];

// Carregando especificações do autômato e casos de teste
const automatonSpecs = loadAutomatonSpecs(automatonSpecsPath);
const testCases = loadTestCases(testCasesPath);

// Criando instância do DFA
const dfa = new DFA(automatonSpecs);

// Executando testes e salvando resultados no arquivo
runTestsAndSaveResults(dfa, testCases, outputFilePath);