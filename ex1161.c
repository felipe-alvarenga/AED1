#include <stdio.h>

unsigned long long int calculaFatorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    
    unsigned long long int fatorial = 1;
    for (int i = 2; i <= n; i++) {
        fatorial *= i;
    }
    
    return fatorial;
}

int main(void) {
    int n1, n2;
    while (scanf("%d %d", &n1, &n2) != EOF) {
        unsigned long long int resultado = calculaFatorial(n1) + calculaFatorial(n2);
        printf("%llu\n", resultado);
    }
    
    return 0;
}
