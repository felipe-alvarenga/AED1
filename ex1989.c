#include <stdio.h>
#include <stdbool.h>

// Função para calcular o total de tempo assistido
unsigned long long int calcularTempoTotal(int seasons, int eps[]) {
    unsigned long long int total = 0, somaParcial = 0;
    for (int i = 0; i < seasons; i++) {
        somaParcial += eps[i];
        total += somaParcial;
    }
    return total;
}

int main() {
    int seasons, duration;

    while (true) {
        scanf("%d %d", &seasons, &duration);

        if (seasons == -1 && duration == -1)
            break;

        int eps[seasons];
        for (int i = 0; i < seasons; i++) {
            scanf("%d", &eps[i]);
        }

        unsigned long long int total = calcularTempoTotal(seasons, eps);

        printf("%llu\n", duration * total);
    }

    return 0;
}
