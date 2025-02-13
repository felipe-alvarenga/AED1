#include <stdio.h>
#include <stdlib.h>

int inversoes = 0;

void intercalar(int esq[], int tam_esq, int dir[], int tam_dir, int resultado[]) {
    int i = 0, j = 0, k = 0;

    while (i < tam_esq && j < tam_dir) {
        if (esq[i] < dir[j]) {
            resultado[k++] = esq[i++];
        } else {
            inversoes += tam_esq - i;
            resultado[k++] = dir[j++];
        }
    }

    while (i < tam_esq) {
        resultado[k++] = esq[i++];
    }

    while (j < tam_dir) {
        resultado[k++] = dir[j++];
    }
}

void mergeSort(int vetor[], int tamanho) {
    if (tamanho <= 1)
        return;

    int meio = tamanho / 2;
    int *esq = malloc(meio * sizeof(int));
    int *dir = malloc((tamanho - meio) * sizeof(int));

    for (int i = 0; i < meio; ++i)
        esq[i] = vetor[i];

    for (int i = meio; i < tamanho; ++i)
        dir[i - meio] = vetor[i];

    mergeSort(esq, meio);
    mergeSort(dir, tamanho - meio);

    intercalar(esq, meio, dir, tamanho - meio, vetor);

    free(esq);
    free(dir);
}

int main() {
    int tamanho;

    while (scanf("%d", &tamanho) != EOF) {
        int *inicio = malloc(tamanho * sizeof(int));
        int *fim = malloc(tamanho * sizeof(int));

        for (int i = 0; i < tamanho; ++i)
            scanf("%d", &inicio[i]);

        for (int i = 0; i < tamanho; ++i)
            scanf("%d", &fim[i]);

        int *mapa = malloc((tamanho + 1) * sizeof(int));

        for (int i = 0; i < tamanho; ++i)
            mapa[inicio[i]] = i + 1;

        for (int i = 0; i < tamanho; ++i)
            fim[i] = mapa[fim[i]];

        inversoes = 0;
        mergeSort(fim, tamanho);

        printf("%d\n", inversoes);

        free(inicio);
        free(fim);
        free(mapa);
    }

    return 0;
}
