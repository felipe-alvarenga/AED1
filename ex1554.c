#include <stdio.h>
#include <math.h>

int main() {
    int c, n, x, y, bola, x1, y1;
    float d, menorD;

    // Leitura do número de casos de teste
    scanf("%d", &c);

    // Loop para cada caso de teste
    while (c--) {
        // Leitura do número de bolas
        scanf("%d", &n);

        // Leitura das coordenadas da bola branca
        scanf("%d %d", &x, &y);

        // Inicializa a menor distância com um valor muito alto
        menorD = 100000.0;

        // Loop para ler as coordenadas das bolas e calcular as distâncias
        for (int i = 0; i < n; i++) {
            // Leitura das coordenadas de uma bola
            scanf("%d %d", &x1, &y1);

            // Cálculo da distância entre as bolas
            d = sqrt(pow((x1 - x), 2) + pow((y1 - y), 2));

            // Se a distância for menor que a menor distância atual, atualiza a menor distância
            if (d < menorD) {
                menorD = d;
                bola = i + 1; // Armazena o número da bola mais próxima
            }
        }

        // Imprime o número da bola mais próxima
        printf("%d\n", bola);
    }

    return 0;
}
