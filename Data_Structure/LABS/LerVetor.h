#include <stdio.h>

void LerVetor(int *T, int n){

    int i;
    for(int i = 0; i < (n - 1); i++){
        printf("Digite um número: ");
        scanf("%d", &T[i]);

    }

}