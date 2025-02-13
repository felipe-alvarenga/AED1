#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM_MAX 10005

int divisor;

int comparar(const void *a, const void *b) {
    int numA = *(int *)a, numB = *(int *)b;
    int modA = numA % divisor, modB = numB % divisor;
    
    if (numA < 0) modA = -1 * (abs(numA) % divisor);
    if (numB < 0) modB = -1 * (abs(numB) % divisor);
    
    if (modA != modB) return modA - modB;
    if ((numA & 1) && !(numB & 1)) return -1;
    if (!(numA & 1) && (numB & 1)) return 1;
    if ((numA & 1) && (numB & 1)) return numB - numA;
    
    return numA - numB;
}

int main() {
    while (1) {
        int quantidade;
        scanf("%d %d", &quantidade, &divisor);
        
        if (quantidade == 0 && divisor == 0) {
            printf("0 0\n");
            break;
        }
        
        int numeros[TAM_MAX];
        for (int i = 0; i < quantidade; i++) {
            scanf("%d", &numeros[i]);
        }
        
        qsort(numeros, quantidade, sizeof(int), comparar);
        
        printf("%d %d\n", quantidade, divisor);
        for (int i = 0; i < quantidade; i++) {
            printf("%d\n", numeros[i]);
        }
    }
    
    return 0;
}
