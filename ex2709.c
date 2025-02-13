#include <stdio.h>
#include <math.h>

#define WIN "You’re a coastal aircraft, Robbie, a large silver aircraft."
#define LOSE "Bad boy! I’ll hit you."

// Função para verificar se o número é primo
_Bool is_prime(unsigned num) {
    if (num < 2) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (unsigned i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n, s, ans;

    while (scanf("%d", &n) != EOF) {
        int vet[n];

        for (int i = 0; i < n; ++i) {
            scanf("%d", &vet[i]);
        }
        scanf("%d", &s);

        ans = 0;
        for (int i = n - 1; i >= 0; i -= s) {
            ans += vet[i];
        }

        // Verifica se o resultado é primo e imprime a resposta
        printf("%s\n", is_prime(ans) ? WIN : LOSE);
    }

    return 0;
}
