#include <stdio.h>

// Função para calcular o total de números
int totalNumeros(int n) {
    return (n * (n + 1)) / 2 + 1; // Fórmula para a soma dos primeiros n números + 1 (para o zero)
}

// Função para imprimir a sequência de números
void imprimirSequencia(int n) {
    printf("0");
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            printf(" %d", i);
        }
    }
    printf("\n");
}

int main(void) {
    int n, casos = 1;

    while (scanf("%d", &n) != EOF) {
        int total = totalNumeros(n);

        printf("Caso %d: %d numero%s\n", casos, total, total == 1 ? "" : "s");
        imprimirSequencia(n);
        printf("\n");

        casos++;
    }

    return 0;
}
