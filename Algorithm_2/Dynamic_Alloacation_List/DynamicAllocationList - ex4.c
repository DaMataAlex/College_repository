#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void limpar_terminal(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

typedef struct{
    double reais;
}vetor;

int menu(){
    printf("Defina o tamanho do vetor: ");
    int tamanho_vetor;
    scanf("%d", &tamanho_vetor);
    getchar();
    return tamanho_vetor;
}

void fazer_vetor(vetor *novo_vetor, int tamanho_vetor){
    for(int i = 0; i < tamanho_vetor; i++){
        scanf("%lf", &novo_vetor[i].reais);
    }
    limpar_terminal();
    printf("Vetor inserido com sucesso");
    getchar();
    getchar();
    limpar_terminal();
    printf("Seu vetor eh:\n");
    for(int i = 0; i < tamanho_vetor; i++){
        printf("%.0lf ", novo_vetor[i].reais);
    }
    getchar();
    limpar_terminal();
}

int main(){

    vetor *vetor_usuario = NULL;
    int tamanho_vetor = menu();

    vetor_usuario = realloc(vetor_usuario, tamanho_vetor * sizeof(vetor));
    fazer_vetor(vetor_usuario, tamanho_vetor);

    return 0;
}