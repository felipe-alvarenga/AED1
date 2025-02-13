#include <stdio.h>
#include <stdbool.h>

int obterMaximo(int a, int b) {
    if(a > b)
        return a;
    return b;
}

int mochilaBinaria(int capacidade, int pizzas[], int tempos[], int n) {
    // Caso base
    if(n == 0 || capacidade == 0)
        return 0;

    // Se o número de pizzas de um pedido for maior que a capacidade restante,
    // então este pedido não pode ser incluído na solução ótima.
    if(pizzas[n-1] > capacidade)
        return mochilaBinaria(capacidade, pizzas, tempos, n-1);

    // Retorna o máximo entre os dois casos:
    // 1 - O pedido foi incluído
    // 2 - O pedido não foi incluído
    else
        return obterMaximo(tempos[n-1] + mochilaBinaria(capacidade - pizzas[n-1], pizzas, tempos, n-1),
                            mochilaBinaria(capacidade, pizzas, tempos, n-1));
}

int main() {
    int n, capacidade, tempo, qt, min, i;

    while(true) {
        scanf("%d", &n);

        if(n == 0)
            break;
        
        scanf("%d", &capacidade);

        int temposTotais[n], quantidadesPizzas[n];
        for(i = 0; i < n; i++)
            scanf("%d %d", &temposTotais[i], &quantidadesPizzas[i]);

        min = mochilaBinaria(capacidade, quantidadesPizzas, temposTotais, n);

        printf("%d min.\n", min);
    }
    
    return 0;
}
