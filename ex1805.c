#include <stdio.h>

int main() {
    long long int a, b;
    unsigned long long int soma1, soma2, total;

    // Leitura dos valores de a e b
    scanf("%lli %lli", &a, &b);

    // Cálculo das somas dos n primeiros números naturais
    soma1 = a * (a + 1) / 2;
    soma2 = b * (b + 1) / 2;

    // Cálculo do total, subtraindo a soma de 1 a a e somando a
    total = soma2 - soma1 + a;

    // Impressão do resultado
    printf("%llu\n", total);

    return 0;
}
