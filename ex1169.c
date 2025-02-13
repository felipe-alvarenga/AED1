#include <stdio.h>
#include <math.h>

int main() {
    int testes, casas, i;
    unsigned long long int quantidade;

    scanf("%d", &testes);

    while (testes--) {
        scanf("%d", &casas);

        if (casas == 64) {
            printf("1537228672809129 kg\n");
        } else {
            quantidade = 0;

            for (i = 0; i < casas; i++) {
                quantidade += pow(2, i);
            }

            // Conversão de grãos para quilos
            quantidade /= 12;   // De grãos para gramas
            quantidade /= 1000;  // De gramas para quilos

            printf("%llu kg\n", quantidade);
        }
    }

    return 0;
}
