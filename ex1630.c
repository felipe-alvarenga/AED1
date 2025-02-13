#include <stdio.h>

int calcularMDC(int a, int b) {
    int resto = a % b;

    while (resto != 0) {
        a = b;
        b = resto;
        resto = a % b;
    }

    return b;
}

int main() {
    int largura, altura, quantidadeEstacas, aux, divisorComum;

    while (scanf("%d %d", &largura, &altura) != EOF) {
        // Em um terreno quadrado, 4 estacas, uma em cada extremo, basta!
        if (largura == altura)
            printf("4\n");
        else {
            // Garantindo que a largura seja sempre menor ou igual à altura
            if (largura > altura) {
                aux = largura;
                largura = altura;
                altura = aux;
            }

            // Caso não seja um quadrado, divide as estacas com um intervalo igual ao MDC entre a largura e a altura
            divisorComum = calcularMDC(largura, altura);
            printf("%d\n", 2 * (largura / divisorComum) + 2 * (altura / divisorComum));
        }
    }

    return 0;
}
