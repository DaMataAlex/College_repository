#include <stdio.h>
#include "LerVetor.h"
#include "ImprimirVetor.h"
#include "QuickSort.h";

int main(){

    int T[10];
    int n = 10;

    printf("Digite 10 números para o vetor:\n");
    LerVetor(T, n);

    printf("Array antes da ordenação:\n");
    ImprimirVetor(T, n);

    QuickSort(T, n);

    printf("Array depois da ordenação:\n");
    ImprimirVetor(T, n);

    return 0;
}