#include <stdio.h>
#include <stdlib.h>
#include "LerVetor.h";
#include "ImprimirVetor.h";
#include "SelectionSort.h";

int main(){

    int T[10];
    int n = 10;

    printf("Digite dez números para o vetor:\n");
    LerVetor(T, n);

    printf("Array antes da ordenação:\n");
    ImprimirVetor(T, n);

    SelectionSort(T, n);

    printf("Array depois da ordenação:\n");
    ImprimirVetor(T, n);

    return 0;
}