#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Aresta;

// Função de comparação para ordenar as arestas pelo peso
int comparar(const void *a, const void *b) {
    return ((Aresta *)a)->weight - ((Aresta *)b)->weight;
}

// Função para encontrar o representante de um conjunto
int find(int *parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

// Função para unir dois conjuntos
void union_sets(int *parent, int *rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    int m, n;
    
    // Continuar até m e n serem 0
    while (scanf("%d %d", &m, &n) && (m != 0 || n != 0)) {
        Aresta arestas[n];
        int total_custo = 0;
        
        // Ler as arestas
        for (int i = 0; i < n; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            arestas[i].u = x;
            arestas[i].v = y;
            arestas[i].weight = z;
            total_custo += z;  // Somar o custo total das estradas
        }
        
        // Ordenar as arestas pelo peso (custo)
        qsort(arestas, n, sizeof(Aresta), comparar);
        
        // Kruskal's Algorithm
        int parent[m], rank[m];
        for (int i = 0; i < m; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        
        int mst_custo = 0;
        int arestas_usadas = 0;
        
        for (int i = 0; i < n; i++) {
            if (find(parent, arestas[i].u) != find(parent, arestas[i].v)) {
                union_sets(parent, rank, arestas[i].u, arestas[i].v);
                mst_custo += arestas[i].weight;
                arestas_usadas++;
                if (arestas_usadas == m - 1) break;  // MST tem m-1 arestas
            }
        }
        
        // A economia é a diferença entre o custo total e o custo da MST
        printf("%d\n", total_custo - mst_custo);
    }
    
    return 0;
}
