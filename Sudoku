#include <stdio.h>
#define M 9

int sudoku[M][M];

//Verifica se tem numeros repetidos na linha
int vlinha(int a){
    int numeros[M + 1] = {0};

    for (int i = 0; i < M; ++i){
        int num = sudoku[a][i];
        if (numeros[num]){
            return 0;
        }
        numeros[num] = 1;
    }
    return 1;
}

//Verifica se tem numeros repetidos na coluna
int vcoluna(int b){
    int numeros[M + 1] = {0};

    for (int j = 0; j < M; ++j){
        int num = sudoku[j][b];
        if (numeros[num]){
            return 0;
        }
        numeros[num] = 1;
    }
    return 1;
}

//Verifica se os numeros se repetem numa matriz 3x3
int ver3x3(int c){
    int numeros[M + 1] = {0};
    int a = (c/3)*3;
    int b = (c%3)*3;

    for (int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            int num = sudoku[a+i][b+j];
            if(numeros[num]){
                return 0;
            }
            numeros[num] = 1;
        }
    }
    return 1;
}

int main() {
    int inst;
    scanf("%d", &inst); //numero de instancias

    for(int k = 1; k <= inst; ++k){ //le o tabuleiro
        for(int i = 0; i < M; ++i){
            for(int j =0; j < M; ++j){
                scanf("%d", &sudoku[i][j]);
            }
        }
        printf("Instancia %d\n", k); //mostra na tela a instancia
        int vale = 1;

        for(int i = 0; i < M; ++i){ //verifica se as funções encontraram numeros repetidos
            if(!vlinha(i) || !vcoluna(i) || !ver3x3(i)){
                vale = 0;
                break;
            }
        }

        if (vale){
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }
    return 0;
}
