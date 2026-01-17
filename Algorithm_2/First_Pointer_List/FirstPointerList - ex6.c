/*6. Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
Imprima o endereco de cada posicao dessa matriz.*/

#include <stdio.h>
#include <stdlib.h>

void clear(){

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void main(){

    float square[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%f", &square[i][j]);
        }
    }
    clear();

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("Posicao [%d][%d] = %.1f; Endereco = %p\n", i, j, square[i][j], &square[i][j]);
        }
    }
}