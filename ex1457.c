#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Função que calcula o fatorial 'k' de um número 'n'
unsigned long long int fatorialK(int n, int k){
    int i;
    unsigned long long int resultado = n;
    // Resultado armazenará n * n-k * n-(i+1)k ...
    i = 1;
    // Loop 'infinito'
    while(true){
        // Caso a diferença seja inferior a 1, encerra.
        if((n - i*k) < 1)
            break;
        
        resultado *= n - i*k;
        i++;
    }

    return resultado;
}

int main(){
    int n, t, k, i, j;
    char c, numeroStr[121];
    unsigned long long int resultado;    
    bool flag;

    scanf("%d", &t);

    while(t--){
        // Lê o número com os '!' e armazena em uma string.
        scanf("%s", numeroStr);
        
        k = 0;
        // Loop para contar a quantidade de Ks.
        for(i = strlen(numeroStr) - 1; ; i--){
            // Enquanto o caractere indicado por numeroStr[i] for '!', incrementa a quantidade de Ks. Encerra o laço quando encontra um número.
            if(numeroStr[i] != '!')
                break;
            else
                k++;
        }
        /*
        Ao final do loop, a variável 'i' possuirá a posição do último dígito do número.
        Ao adicionar numeroStr[i+1] = '\0' elimina todos caracteres a partir da posição i+1. Ou seja, elimina todas exclamações da string
        Restando apenas o número.
        */
        numeroStr[i+1] = '\0';

        // A função atoi converte a string para um número inteiro e armazena na variável n.
        n = atoi(numeroStr);
        
        // Chama, agora, a função para cálculo do fatorial.
        resultado = fatorialK(n, k); 
        printf("%llu\n", resultado);
    }
    return 0;
}
