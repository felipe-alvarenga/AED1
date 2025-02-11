#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

// Função para trocar os valores de duas variáveis
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função de partição para o QuickSort
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

// Função QuickSort
void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// Função para calcular os divisores de um número
void c_divisors(int c, int divisors[]) {
    int idx = 0;
    for (int i = 1; i <= sqrt(c); i++) {
        if (c % i == 0) {
            divisors[idx++] = i;
            if (c / i != i) {
                divisors[idx++] = c / i;
            }
        }
    }
}

// Função para verificar as condições
bool verify(int n, int a, int b, int d) {
    return (n % a == 0 && n % b != 0 && d % n != 0);
}

int main() {
    int a, b, c, d;

    // Lê os valores de a, b, c e d
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int divisors[1000] = {0}; // Inicializa o vetor de divisores com 0

    // Calcula os divisores de c
    c_divisors(c, divisors);

    // Ordena os divisores
    quickSort(divisors, 0, 999);

    int ans = -1;

    // Verifica cada divisor para encontrar o primeiro que satisfaça as condições
    for (int i = 0; i < 1000; i++) {
        if (divisors[i] == 0) continue; // Ignora os valores 0
        if (verify(divisors[i], a, b, d)) {
            ans = divisors[i];
            break;
        }
    }

    // Imprime a resposta
    printf("%d\n", ans);

    return 0;
}
