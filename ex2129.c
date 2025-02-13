#include <stdio.h>

typedef unsigned long long ull;

ull nao_zero(ull n){
    ull x, y, potenciaX, ultimoY;

    if(n == 0 || n == 1)
        return 1;

    x = n / 5;
    y = n % 5;

    // Obtém o último dígito de 2^x
    potenciaX = x % 4;
    switch(potenciaX){
        case 0:
            potenciaX = 1;
            break;
        
        case 1:
            potenciaX = 2;
            break;
        
        case 2:
            potenciaX = 4;
            break;
        
        case 3:
            potenciaX = 8;
            break;
    }

    // Obtém o último dígito do fatorial de y
    switch(y){
        case 0:
            ultimoY = 1;
            break; 
        case 1:
            ultimoY = 1;
            break; 
        case 2:
            ultimoY = 2;
            break; 
        case 3:
            ultimoY = 6;
            break; 
        case 4:
            ultimoY = 4;
            break; 
        default:
            ultimoY = 0;
    }

    return (potenciaX * nao_zero(x) * ultimoY);
}

int main(){
    ull n, resultado, instancia = 1;

    while(scanf("%llu", &n) != EOF){
        printf("Instancia %llu\n", instancia); 
        instancia++;

        resultado = nao_zero(n);
        while(resultado >= 10)
            resultado = resultado % 10;

        printf("%llu\n\n", resultado);
    }
    return 0;
}
