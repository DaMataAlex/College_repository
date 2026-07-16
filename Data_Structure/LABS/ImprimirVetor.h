#include <stdio.h>

void ImprimirVetor(int *T, int n){
    int i;
    for(int i = 0; i <= (n-1); i++){
        printf("%d ", T[i]);
    }
    printf("\n");

}