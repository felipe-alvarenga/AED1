#include <stdio.h>
#include <stdbool.h>

// Função para converter um número para a base 32 e imprimir o resultado
void converterParaBase32(unsigned long long int n) {
    char tabela[33] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
    int num[13], inseridos = 0;

    if (n == 0) {
        printf("0\n");
        return;
    }

    while (n != 0) {
        num[inseridos++] = n % 32;
        n /= 32;
    }

    for (int i = inseridos - 1; i >= 0; i--) {
        printf("%c", tabela[num[i]]);
    }
    printf("\n");
}

int main() {
    unsigned long long int n;

    while (true) {
        scanf("%llu", &n);

        if (n == 0) {
            printf("0\n");
            break;
        }

        converterParaBase32(n);
    }

    return 0;
}
