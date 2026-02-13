#include <stdio.h>
#include <stdlib.h>

int main(){

    //setting the variable that corresponds to the size of the array, which it's given by the user
    int array_size;
    scanf("%d", &array_size);

    int *array;

    //allocating memory
    array = (int *) malloc(array_size * sizeof(int));

    //the 'malloc' built-in function allways returns a pointer to the allocated memory.
    //if it fails to allocate the memory, it will return a NULL adress
    if(array == NULL){
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    }

    //scaning the numbers of the array
    for(int i = 0; i < array_size; i++){
        scanf("%d", &array[i]);
    }

    //printing the array numbers
    for(int i = 0; i < array_size; i++){
        printf("Variavel: %d; Endereco: %d\n", array[i], &array[i]);

    }

    free(array);

    return 0;

}