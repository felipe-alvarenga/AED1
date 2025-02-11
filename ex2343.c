#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, x, y;

    // Lê o número de raios
    scanf("%d", &n);

    bool coord[501][501] = {false}; // Inicializa o vetor booleano com todos os valores como falso

    bool result = false;

    // Processa os raios
    for(int i = 0; i < n; i++) {
        // Lê as coordenadas onde o raio caiu
        scanf("%d %d", &x, &y);

        // Se a coordenada já foi atingida, encerra o loop
        if(coord[x][y]) {
            result = true;
            break;
        }

        // Marca a coordenada como atingida
        coord[x][y] = true;
    }

    // Imprime o resultado
    printf("%d\n", result ? 1 : 0);

    return 0;
}
