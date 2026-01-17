/*5. Crie um programa que contenha um array de float contendo 10 elementos. Imprima
o endereco de cada posicao desse array.*/

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

    float array[9];

    printf("Digite os 10 valores da array:\n");

    for(int i = 0; i < 10; i++){
        scanf("%f", &array[i]);
    }

    clear();

    for(int i = 0; i < 10; i++){
        printf("Array[%d] = %.1f; Endereco = %p\n", i, array[i], &array[i]);
    }

}