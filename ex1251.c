#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 1005
#define ASCII 256

typedef struct {
    int frequencia;
    char caractere;
} Par;

int comparar(const void *a, const void *b) {
    Par *par1 = (Par *)a;
    Par *par2 = (Par *)b;

    if (par1->frequencia == par2->frequencia)
        return par2->caractere - par1->caractere;

    return par1->frequencia - par2->frequencia;
}

int main() {
    char entrada[TAM_MAX];
    int primeiroCaso = 1;

    while (fgets(entrada, TAM_MAX, stdin)) {
        int contagem[ASCII] = {0};
        Par ordenado[ASCII];
        int total = 0;

        for (int i = 0; entrada[i] != '\0' && entrada[i] != '\n'; i++) {
            contagem[(unsigned char)entrada[i]]++;
        }

        for (int i = 0; i < ASCII; i++) {
            if (contagem[i] > 0) {
                ordenado[total].caractere = (char)i;
                ordenado[total].frequencia = contagem[i];
                total++;
            }
        }

        qsort(ordenado, total, sizeof(Par), comparar);

        if (!primeiroCaso)
            printf("\n");

        primeiroCaso = 0;

        for (int i = 0; i < total; i++) {
            printf("%d %d\n", ordenado[i].caractere, ordenado[i].frequencia);
        }
    }

    return 0;
}
