#include <stdio.h>

// Definição do tabuleiro de Sudoku como uma matriz global
int sudoku[9][9];

int verificaQuadrante(int);
int checaLinha(int);
int checaColuna(int);

int main() {
    int jogos;
    char* status;

    // Lê a quantidade de jogos a serem verificados
    scanf("%d", &jogos);

    // Processa cada tabuleiro
    for (int caso = 1; caso <= jogos; caso++) {
        // Preenchendo o tabuleiro
        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                scanf("%d", &sudoku[x][y]);
            }
        }

        printf("Jogo %d\n", caso);

        // Assume inicialmente que o tabuleiro é válido
        status = "SIM";

        // Checa cada linha, coluna e bloco 3x3
        for (int i = 0; i < 9; i++) {
            if (!checaLinha(i) || !checaColuna(i) || !verificaQuadrante(i)) {
                status = "NAO";
                break;
            }
        }

        printf("%s\n\n", status);
    }

    return 0;
}

// Função para verificar uma linha do tabuleiro
int checaLinha(int linha) {
    int encontrado[10] = {0};  // Array para rastrear os números

    for (int i = 0; i < 9; i++) {
        if (encontrado[sudoku[linha][i]])  // Se o número já foi encontrado, retorna falso
            return 0;
        encontrado[sudoku[linha][i]] = 1;  // Marca o número como encontrado
    }
    return 1;
}

// Função para verificar uma coluna do tabuleiro
int checaColuna(int coluna) {
    int encontrado[10] = {0};  // Array para rastrear os números

    for (int i = 0; i < 9; i++) {
        if (encontrado[sudoku[i][coluna]])  // Se o número já foi encontrado, retorna falso
            return 0;
        encontrado[sudoku[i][coluna]] = 1;  // Marca o número como encontrado
    }
    return 1;
}

// Função para verificar um bloco 3x3 no tabuleiro
int verificaQuadrante(int bloco) {
    int encontrado[10] = {0};  // Array para rastrear os números
    int inicioX = 3 * (bloco / 3), inicioY = 3 * (bloco % 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int valor = sudoku[inicioX + i][inicioY + j];
            if (encontrado[valor])  // Se o número já foi encontrado, retorna falso
                return 0;
            encontrado[valor] = 1;  // Marca o número como encontrado
        }
    }

    return 1;
}
