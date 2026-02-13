#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void limpar_tela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int verificar_letra(int *comparado, int modelo){
    int existe = 0;

    for(int i = 0; i < sizeof(comparado); i++){
        if(comparado[i] == modelo){
            existe = 1;
            break;
        }
    }

    return existe;
}
int main(){

    //definindo os ponteiros e as variaveis
    int **parray = NULL;
    int qtd_linhas, qtd_colunas;

    //escaneando a quantidade de linhas e colunas
    printf("Digite a quantidade de linhas: ");
    scanf("%d", &qtd_linhas);
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &qtd_colunas);

    limpar_tela();

    //alocando a matriz dinamicamente
    parray = (int **) malloc(qtd_linhas * sizeof(int*));

    for(int i = 0; i < qtd_linhas; i++){
        parray[i] = (int *) malloc(qtd_colunas * sizeof(int));
    }

    //lendo os valores digitados pelo usuario
    int counter_linha = 0;
    for(int i = 0; i < qtd_linhas; i++){
        counter_linha++;
        printf("Digite os valores da linha %d:\n", counter_linha);
        for(int j = 0; j < qtd_colunas; j++){
            scanf("%d", &parray[i][j]);
        }
    }

    limpar_tela();

    //printando a matriz
    printf("Matriz digitada:\n\n");
    for(int i = 0; i < qtd_linhas; i++){
        for(int j = 0; j < qtd_colunas; j++){
            printf("%d ", parray[i][j]);
        }
        printf("\n");
    }

    int *pvet_copia;
    pvet_copia = (int *) calloc (qtd_linhas * qtd_colunas, sizeof(int));

    for(int i = 0; i < qtd_linhas; i++){
        for(int j = 0; j < qtd_colunas; j++){
            if(verificar_letra(pvet_copia, parray[i][j]) == 0){
                pvet_copia[i] = parray[i][j];
            }
        }
        
    }

    printf("\nVetor gerado:\n");
    for(int i = 0; i < sizeof(pvet_copia);i++){
        printf("%d ", *pvet_copia);
    }
    
    return 0;

}