#include <stdio.h>
#include <stdlib.h>

int main(){

    int N;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);

    int *vetor;

    vetor = (int*) malloc(N * sizeof(int));

    if(vetor == NULL){
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    }

    for(int i = 0; i < N; i++){
        printf("Digite o valor no indice %d: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor completo:\n");
    for(int i = 0; i < N; i++){
        printf("%d", vetor[i]);
        if(i < N - 1){
            printf(" ");
        }else{
            printf("\n");
        }
    }

    free(vetor);

    return 0;

}