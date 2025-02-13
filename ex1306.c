#include <stdio.h>

int main() {
    int ruas, combinacoes, caso = 1, divInteira;
    float divFlutuante;

    while (1) {
        scanf("%d %d", &ruas, &combinacoes);

        if (!combinacoes && !ruas)
            break;

        // Caso o número de ruas seja maior que o número de combinações possíveis
        if (ruas > (combinacoes * 26 + combinacoes))
            printf("Case %d: impossible\n", caso);
        else {
            // Caso o número de ruas seja menor que a quantidade de números, nenhum sufixo será necessário.
            if (ruas <= combinacoes)
                printf("Case %d: 0\n", caso);
            else {
                divInteira = ruas / combinacoes;
                divFlutuante = (float)ruas / combinacoes;

                if (divFlutuante <= divInteira)
                    printf("Case %d: %d\n", caso, divInteira - 1);
                else
                    printf("Case %d: %d\n", caso, divInteira);
            }
        }

        caso++;
    }

    return 0;
}
