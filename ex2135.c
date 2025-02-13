#include <stdio.h>
#include <stdbool.h>

int main(){
    int n, i, instancia = 1, soma;
    bool encontrou;

    while(scanf("%d", &n) != EOF){
        int vetor[n];

        for(i = 0; i < n; i++)
            scanf("%d", &vetor[i]);

        soma = vetor[0];
        
        encontrou = false;
        for(i = 1; i < n; i++){
            if(soma == vetor[i]){
                encontrou = true;
                break;
            }
            soma += vetor[i];
        }

        if(vetor[0] == 0)
            printf("Instancia %d\n0\n", instancia);
        else{
            if(encontrou)
                printf("Instancia %d\n%d\n", instancia, vetor[i]);
            else 
                printf("Instancia %d\nnao achei\n", instancia);
        }
        
        printf("\n");
        instancia++;
    }

    return 0;
}
