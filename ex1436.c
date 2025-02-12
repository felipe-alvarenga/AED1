#include <stdio.h>

int main(void) {
    int T, N;

    // Leitura do número de casos de teste
    scanf("%d", &T);

    // Loop para cada caso de teste
    for (int i = 1; i <= T; i++) {
        // Leitura do número de elementos (idades) no caso de teste
        scanf("%d", &N);
        
        // Alocação do vetor de idades
        int idades[N];
        
        // Leitura das idades
        for (int j = 0; j < N; j++) {
            scanf("%d", &idades[j]);
        }

        // Exibição do resultado para o caso de teste
        printf("Case %d: %d\n", i, idades[N / 2]);
    }

    return 0;
}
