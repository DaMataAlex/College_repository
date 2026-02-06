#include <stdio.h>
#include <stdlib.h>

int main(){

    int array_size;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &array_size);

    int *parray_size;

    parray_size = (int *) malloc(array_size * sizeof(int));

    printf("\nDigite os valores:\n");

    int *p2;
    p2 = parray_size;
    for(int i = 0; i < array_size; i++){
        scanf("%d", p2);
        p2++;
    }

    p2 = parray_size;
    for(int i = 0;  i < array_size; i++){
        printf("\nVariavel no endereco %d : %d\n", p2, *p2);
        p2++;
    }

    free(parray_size);

    return 0;
}
