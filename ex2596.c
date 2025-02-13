#include <stdio.h>
#include <stdbool.h>

// Retorna verdadeiro, caso o número de divisores seja par, e falso caso contrário.
bool contaDivisores(int n){
    int divisores = 1, i;

    for(i = 2; i <= n; i++)
        if(n % i == 0)
            divisores++;

    if(divisores % 2 == 0)
        return true;
    
    return false;
}

int main(){
    int casos, n, i, pares;
    scanf("%d", &casos);

    while(casos--){
        scanf("%d", &n);

        pares = 0;
        for(i = 2; i <= n; i++){
            if(contaDivisores(i))
                pares++;
        }

        printf("%d\n", n - (n - pares));
    }

    return 0;
}
