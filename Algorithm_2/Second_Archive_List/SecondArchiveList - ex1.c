#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funcao auxiliar
void limpar_terminal(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//menu
int menu(){

    printf("O que vc quer da sua vida?\n\n");
    printf("1 - Criar/abrir arquivo e inserir caracteres.\n");
    printf("2 - Ler arquivo ja existente.\n");
    printf("3 - Sair do programa.\n\n");

    int opcao;
    scanf(" %d", &opcao);
    limpar_terminal();
    return opcao;
}

//gerenciamento do arquivo
void abrir_arquivo(FILE *pArquivo){
    limpar_terminal();
    printf("Como voce deseja abrir o arquivo?\n\n");
    printf("1 - Escrever no arquivo já existente caso ele exista.\n");
    printf("2 - Sobrescrever o arquivo existe.\n");
    
    int opcao;
    scanf("%d", &opcao);

    if(opcao == 1){ 
        pArquivo = fopen("arq.txt", "a");
    }else if(opcao == 2){
        pArquivo = fopen("arq.txt", "w");
    }

    limpar_terminal();

    char c;

    printf("Digite os caracteres que irao para o arquivo\n");
    printf("Digite 0 para finalizar a operação.\n\n");
    while((scanf("%c", &c)) == 1 && c != '0'){
        fprintf(pArquivo, "%c", c);
    }

    fclose(pArquivo);
    limpar_terminal();
}

void ler_arquivo(FILE *pArquivo){
    pArquivo = fopen("arq.txt", "r");

    int c;

    while ((c = fgetc(pArquivo)) != EOF){
        printf("%c", c);
    }

    printf("\nPressione ENTER para voltar para o menu principal.\n\n");
    getchar(); getchar();

    fclose(pArquivo);
    limpar_terminal();
}

int main(){

    int opcao;
    opcao = menu();
    FILE *pArq;

    while(1){
        while(opcao != 1 && opcao != 2 && opcao != 3){
            limpar_terminal();
            printf("Digite uma opcao valida!\n");
            opcao = menu();
        }

        if(opcao == 1){
            abrir_arquivo(pArq);
            opcao = menu();
        }else if(opcao == 2){
            ler_arquivo(pArq);
            opcao = menu();
        }else{
            exit(0);
        }
    }


    return 0;
}