#include <stdio.h>

// Tabuleiro global
int jogo[9][9];

// Funções de verificação de linha, coluna e quadrado
int verificaLinha(int linha);
int verificaColuna(int coluna);
int verificaQuadrado(int quadrado);

int main() {
    int partidas; // Número de partidas a serem verificadas
    char* resultado;

    // Lê o número de partidas
    scanf("%d", &partidas);

    // Processa cada partida
    for(int k = 1; k <= partidas; k++) {
        // Lê o tabuleiro do jogo
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                scanf("%d", &jogo[i][j]);
            }
        }

        // Inicia o resultado como válido
        resultado = "SIM";
        printf("Instancia %d\n", k);

        // Verifica a validade do tabuleiro
        for(int i = 0; i < 9; i++) {
            if(!verificaLinha(i) || !verificaColuna(i) || !verificaQuadrado(i)) {
                resultado = "NAO"; // Caso encontre algum erro
                break;
            }
        }

        // Imprime o resultado
        printf("%s\n\n", resultado);
    }

    return 0;
}

// Verifica se há repetição em uma linha
int verificaLinha(int linha) {
    int numeros[10] = {0}; // Contador para os números

    // Verifica cada número na linha
    for(int i = 0; i < 9; i++) {
        if(numeros[jogo[linha][i]]) // Se o número já apareceu, retorna 0
            return 0;
        numeros[jogo[linha][i]] += 1; // Marca o número como visto
    }
    return 1; // Caso a linha seja válida
}

// Verifica se há repetição em uma coluna
int verificaColuna(int coluna) {
    int numeros[10] = {0}; // Contador para os números

    // Verifica cada número na coluna
    for(int i = 0; i < 9; i++) {
        if(numeros[jogo[i][coluna]]) // Se o número já apareceu, retorna 0
            return 0;
        numeros[jogo[i][coluna]] += 1; // Marca o número como visto
    }
    return 1; // Caso a coluna seja válida
}

// Verifica se há repetição em um quadrado 3x3
int verificaQuadrado(int quadrado) {
    int numeros[10] = {0}; // Contador para os números
    int linha = 3 * (quadrado / 3), coluna = 3 * (quadrado % 3);

    // Verifica cada número no quadrado 3x3
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(numeros[jogo[linha + i][coluna + j]]) // Se o número já apareceu, retorna 0
                return 0;
            numeros[jogo[linha + i][coluna + j]] += 1; // Marca o número como visto
        }
    }

    return 1; // Caso o quadrado seja válido
}
