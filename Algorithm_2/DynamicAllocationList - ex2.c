#include <stdio.h>
#include <stdlib.h>

int main(){

    double **mat;

    int rows, columns;

    scanf("%d %d", &rows, &columns);

    mat = (double **) malloc(rows * sizeof(double *));

    for(int i = 0; i < rows; i++){
        mat[i] = (double *) malloc(columns * sizeof(double));
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            scanf("%lf", &mat[i][j]);
        }
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("%.2lf ", mat[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < rows; i++){
        free(mat[i]);
    }
    free(mat);

    return 0;
}
