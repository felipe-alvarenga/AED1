#include <stdio.h>

int main(){
    int t, i, n, intervalo, regioes;

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        intervalo = 2;
        regioes = 2;
        for(i = 1; i < n; i++){
            regioes += intervalo;
            intervalo++;
        }

        printf("%d\n", regioes);
    }

    return 0;
}
