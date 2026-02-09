#include <stdio.h>
#include <stdlib.h>

void limpar_terminal(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int menu(){
    int tamanho_vetor;
    printf("Defina o tamanho do vetor: ");
    scanf("%d", &tamanho_vetor);
    return tamanho_vetor;
}

void fazer_vetor(int *novo_vetor, int *tamanho_vetor){
    // leitura do vetor
    for(int i = 0; i < *tamanho_vetor; i++){
        scanf("%d", &novo_vetor[i]);
    }

    for(int i = 0; i < *tamanho_vetor; i++){
        for(int j = i + 1; j < *tamanho_vetor; ){
            if(novo_vetor[i] == novo_vetor[j]){
                
                for(int k = j; k < *tamanho_vetor - 1; k++){
                    novo_vetor[k] = novo_vetor[k + 1];
                }
                (*tamanho_vetor)--;
            } else {
                j++;
            }
        }
    }

    limpar_terminal();
    printf("Seu vetor sem duplicatas:\n");
    for(int i = 0; i < *tamanho_vetor; i++){
        printf("%d ", novo_vetor[i]);
    }
    printf("\n");
}

int main(){
    int *vetor_usuario = NULL;
    int tamanho_vetor = menu();

    vetor_usuario = malloc(tamanho_vetor * sizeof(int));
    if(vetor_usuario == NULL){
        printf("Erro de alocacao de memoria\n");
        return 1;
    }

    fazer_vetor(vetor_usuario, &tamanho_vetor);

    free(vetor_usuario);
    return 0;
}
