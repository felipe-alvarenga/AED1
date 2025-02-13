#include <stdio.h>
#include <math.h>

int main() {
    int numVertices;
    long long int totalArestas;

    // Lê o número de vértices
    scanf("%d", &numVertices);

    // O número total de arestas em um grafo completo é n(n-1)/2, sendo n o número de vértices.
    // Retira n, pois são removidas as arestas que já compõem os lados da pipa (n arestas no total).
    totalArestas = (pow(numVertices, 2) - 3 * numVertices) / 2;

    // Exibe o resultado
    printf("%lli\n", totalArestas);

    return 0;
}
