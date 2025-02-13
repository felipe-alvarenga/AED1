#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool ehPrimo(unsigned long int numero) {
    int i;
    int limite = sqrt(numero);
    
    if (numero < 2) return false;

    for (i = 2; i <= limite; i++) {
        if (numero % i == 0) {
            return false;
        }
    }
    
    return true;
}

int main(void) {
    int casos;
    unsigned long int valor;

    scanf("%d", &casos);
    
    while (casos--) {
        scanf("%lu", &valor);
        printf("%s\n", ehPrimo(valor) ? "Prime" : "Not Prime");
    }

    return 0;
}
