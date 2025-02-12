#include <stdio.h>

void calcularFibonacci(unsigned long long int fib[], int tamanho) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < tamanho; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main(void) {
    int T, N;
    unsigned long long int fib[61];
    
    calcularFibonacci(fib, 61);
    
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        printf("Fib(%d) = %llu\n", N, fib[N]);
    }
    
    return 0;
}
