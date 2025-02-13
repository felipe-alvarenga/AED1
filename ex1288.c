#include <stdio.h>
#include <string.h>

typedef long long ll; // 1LL

ll memoization[200][60]; // Tabela de memorização
ll projeto[60][2]; // Projetos (dano e peso)

ll obterMax(ll a, ll b) {
    if (a >= b)
        return a;
    return b;
}

// Retorna o dano máximo
ll calcularDano(ll pesoRestante, ll indice) {
    if (indice == 0 && pesoRestante >= projeto[indice][1])
        return projeto[0][0];

    else if (indice == 0)
        return 0;

    if (memoization[pesoRestante][indice] != -1)
        return memoization[pesoRestante][indice];

    ll resultado;
    if (pesoRestante - projeto[indice][1] >= 0)
        resultado = obterMax(projeto[indice][0] + calcularDano(pesoRestante - projeto[indice][1], indice - 1), 
                             calcularDano(pesoRestante, indice - 1));
    else
        resultado = calcularDano(pesoRestante, indice - 1);
        
    return memoization[pesoRestante][indice] = resultado;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        ll n, W, resposta, vidaCastelo;

        scanf("%lld", &n);
        memset(memoization, -1, sizeof(memoization));

        for (int i = 0; i < n; ++i) 
            scanf("%lld %lld", &projeto[i][0], &projeto[i][1]);

        scanf("%lld %lld", &W, &vidaCastelo);

        resposta = calcularDano(W, n - 1);

        if (resposta >= vidaCastelo)
            printf("Missao completada com sucesso\n");
        else
            printf("Falha na missao\n");
    }

    return 0;
}
