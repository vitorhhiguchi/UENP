<?php

// Carregar JSON de configuração
$arquivoConfig = 'duplo_bal.json'; // caminho do JSON de entrada
$config = json_decode(file_get_contents($arquivoConfig), true);

// Ler a fita de entrada
$arquivoEntrada = 'entrada.txt';
$fita = str_split(trim(file_get_contents($arquivoEntrada)));

// Parâmetros da máquina de Turing
$estado = $config['initial'];
$estadosFinais = $config['final'];
$branco = $config['white'];
$transicoes = $config['transitions'];
$cabecote = 0; // posição inicial na fita

// Função para encontrar transição
function encontrarTransicao($transicoes, $estadoAtual, $simboloLido) {
    foreach ($transicoes as $transicao) {
        if ($transicao['from'] == $estadoAtual && $transicao['read'] == $simboloLido) {
            return $transicao;
        }
    }
    return null;
}

// Processamento da máquina
while (!in_array($estado, $estadosFinais)) {
    // Símbolo atual na posição do cabeçote
    $simboloAtual = $fita[$cabecote] ?? $branco;

    // Buscar transição
    $transicao = encontrarTransicao($transicoes, $estado, $simboloAtual);
    if (!$transicao) {
        echo "Erro: Transição não encontrada para estado $estado e símbolo $simboloAtual.\n";
        exit(1);
    }

    // Executar transição
    $fita[$cabecote] = $transicao['write']; // escrever na fita
    $estado = $transicao['to']; // mudar de estado
    $cabecote += ($transicao['dir'] == 'R') ? 1 : -1; // mover cabeçote

    // Expandir a fita conforme necessário
    if ($cabecote < 0) {
        array_unshift($fita, $branco);
        $cabecote = 0;
    } elseif ($cabecote >= count($fita)) {
        $fita[] = $branco;
    }
}

// Gravar fita de saída
$arquivoSaida = 'saida.txt';
file_put_contents($arquivoSaida, implode("", $fita));

echo "Processamento concluído! Resultado gravado em $arquivoSaida.\n";
?>