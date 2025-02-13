#include <stdio.h>

int main(void) {
    int baseFelix, baseMarzia, areaNotaTotal;
    double areaFelix, areaMarzia, areaMetade;

    // Lê as bases dos trapézios formados pelos cortes
    scanf("%d %d", &baseFelix, &baseMarzia);

    // A área total da nota é 70 * 160
    areaNotaTotal = 70 * 160;

    // A metade da área da nota original
    areaMetade = areaNotaTotal / 2;

    // Calcula a área do pedaço de Felix (formado por um trapézio)
    areaFelix = ((baseFelix + baseMarzia) * 70) / 2;

    // A área do pedaço de Marzia é o restante da área
    areaMarzia = areaNotaTotal - areaFelix;

    // Se o pedaço de Felix for igual à metade da área, a nota é inválida
    if (areaFelix == areaMetade) {
        printf("0\n");
        return 0;
    }

    // Verifica quem ficou com o pedaço mais valioso (maior área)
    if (areaFelix > areaMarzia)
        printf("1\n");
    else
        printf("2\n");

    return 0;
}
