#include <stdio.h>
#include <stdlib.h>

int main(){

    int linhas, colunas;

    printf("Digite a quantidade de linhas das matrizes: ");
    scanf("%d", &linhas);
    printf("Digite a quantidade de colunas das matrizes: ");
    scanf("%d", &colunas);

    double **matrizA = (double**) malloc(linhas * sizeof(double*));

    if(matrizA == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    for(int i = 0; i < linhas; i++){
        matrizA[i] = (double*) malloc (colunas * sizeof(double));
    }

    printf("\nEscreva os elementos da primeira matriz:\n");

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf("%lf", &matrizA[i][j]);
        }
        printf("\n");
    }

    double **matrizB = (double**) malloc(linhas * sizeof(double*));

    if(matrizB == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    for(int i = 0; i < linhas; i++){
        matrizB[i] = (double*) malloc(colunas * sizeof(double));
    }

    printf("Digite os elementos da segunda matriz:\n");

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf("%lf", &matrizB[i][j]);
        }
        printf("\n");
    }

    double **MatrizSoma = (double**) malloc(linhas * sizeof(double*));

    if(MatrizSoma == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    for(int i = 0; i < linhas; i++){
        MatrizSoma[i] = (double*) malloc(colunas * sizeof(double));
    }

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            MatrizSoma[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    printf("\nResultado da soma das matrizes:\n");

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%.1lf", MatrizSoma[i][j]);
            if(j < colunas - 1){
                printf(" ");
            }
        }
        printf("\n");
    }

    for(int i = 0; i < linhas; i++){
        free(matrizA[i]);
        free(matrizB[i]);
        free(MatrizSoma[i]);
    }

    free(matrizA);
    free(matrizB);
    free(MatrizSoma);

    return 0;

}