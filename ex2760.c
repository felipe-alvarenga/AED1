#include <stdio.h>

int main() {
    char A[101], B[101], C[101];

    // Lê as três strings de entrada
    scanf("%[^\n]%*c", A);
    scanf("%[^\n]%*c", B);
    scanf("%[^\n]%*c", C);

    // Imprime as permutações das strings
    printf("%s%s%s\n", A, B, C);
    printf("%s%s%s\n", B, C, A);
    printf("%s%s%s\n", C, A, B);
    // Imprime as primeiras 10 letras de cada string
    printf("%.10s%.10s%.10s\n", A, B, C);

    return 0;
}
