/*7. Crie um programa que contenha um array de inteiros contendo 5 elementos. Utili-
zando apenas aritmetica de ponteiros, leia esse array do teclado e imprima o dobro
de cada valor lido.*/

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
    int array[5];
    int *pa = array;

    printf("Digite os 5 valores da array\n");
    for(int i = 0; i < 5; i++){
        scanf("%d", pa + i);
    }
    pa = array;

    clear();

    for(int i = 0; i < 5; i++){
        printf("%d\n", *(pa + i) * 2);
    }
}