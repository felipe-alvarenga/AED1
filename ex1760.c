#include <stdio.h>
#include <math.h>

int main(void) {
    double l, areaTotal;

    // Leitura contínua até o fim do arquivo
    while (scanf("%lf", &l) != EOF) {
        // Cálculo da área total
        areaTotal = 2 * sqrt(3) * pow(l, 2) / 5;

        // Impressão da área formatada com duas casas decimais
        printf("%.2lf\n", areaTotal);
    }

    return 0;
}
