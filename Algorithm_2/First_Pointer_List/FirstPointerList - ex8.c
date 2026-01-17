/*Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse
array do teclado e imprima o endereco das posicoes contendo valores pares.*/

#include <stdio.h>
#include <stdlib.h>

void clear(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main(){

    int array[5];

    for(int i = 0; i < 5; i++){
        scanf("%d", &array[i]);
    }

    clear();

    for(int i = 0; i < 5; i++){
        if(array[i] % 2 == 0){
            printf("Array[%d] = %d; Endereco = %p\n", i, array[i], array[i]);
        }
    }

    return 0;

}