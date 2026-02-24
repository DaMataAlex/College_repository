#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("Digite o tamanho do vetor (igual ou maior que 10):\n");
    int tamanho_vet;
    scanf("%d", &tamanho_vet);

    while(tamanho_vet < 10){
        printf("Digite um valor maior ou igual a 10!\n");
        scanf("%d", &tamanho_vet);
    }

    double *vetor_dinamico = malloc(tamanho_vet * sizeof(double));

    if(vetor_dinamico == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    for(int i = 0 ; i < 10; i++){
        vetor_dinamico[i] = rand() % 101;
    }

    printf("As valores nas primeiras dez posicoes do vetor sao:\n");
    for(int i = 0 ; i < 10; i++){
        printf("%.0lf", vetor_dinamico[i]);
        if(i < 9){
            printf(" ");
        }else{
            printf("\n");
        }
    }

    return 0;

}