#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int contarDigitos(unsigned long long int numero) {
    int contador = 0;

    while (numero > 0) {
        contador++;
        numero /= 10;
    }

    return contador;
}

int main(void) {
    unsigned int casos, digitosA, digitosB, potencia, i;
    unsigned long long int numeroA, numeroB, aux, diferenca = 0;
    bool encaixa;

    scanf("%u", &casos);

    while (casos > 0) {
        diferenca = 0;
        scanf("%llu %llu", &numeroA, &numeroB);

        if (numeroB > numeroA) {
            encaixa = false;
        } else {
            digitosA = contarDigitos(numeroA);
            digitosB = contarDigitos(numeroB);

            if (digitosA == digitosB) {
                encaixa = (numeroA == numeroB);
            } else {
                aux = numeroA;
                potencia = digitosB - 1;

                for (i = 0; i < digitosB; i++)
                    aux /= 10;

                for (i = 0; i < digitosA - digitosB; i++) {
                    potencia++;
                    diferenca += (aux % 10) * pow(10, potencia);
                    aux /= 10;
                }

                encaixa = (numeroA - diferenca == numeroB);
            }
        }

        printf(encaixa ? "encaixa\n" : "nao encaixa\n");

        casos--;
    }

    return 0;
}
