#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

void limpar(){
    #ifdef _WIN32
        system("cls");
    
    #else
        system("clear");
    
    #endif
}

typedef struct{
    char rua[MAX];
    char bairro[MAX];
    int numero;
    char CEP[10];
}ENDERECO;


typedef struct {
    char nome[MAX];
    char nascimento[11];
    ENDERECO endereco;
    double salario;
}FUNCIONARIOS;

int menu_principal(){
    printf("====QUESTAO 3 DA LISTA DE ALOCACAO DINAMICA====\n");
    printf("1 - Cadastrar funcionario.\n");
    printf("2 - Imprimir lista de funcionarios.\n");
    printf("3 - Sair do programa.\n\n");

    int opcao;
    scanf("%d", &opcao);

    limpar();
    return opcao;
}

void cadastrar_funcionario(int quantidade_funcionarios, FUNCIONARIOS *banco_funcionarios){
    limpar();
    printf("----Cadastro de funcionarios----\n");

    printf("Digite o nome do funcionario: ");
    fgets(banco_funcionarios[quantidade_funcionarios].nome, MAX, stdin);
    banco_funcionarios[quantidade_funcionarios].nome[strcspn(banco_funcionarios[quantidade_funcionarios].nome, "\n")] = '\0';

    printf("Digite a data de nascimento do funcionario (00/00/0000): ");
    fgets(banco_funcionarios[quantidade_funcionarios].nascimento, MAX, stdin);
    banco_funcionarios[quantidade_funcionarios].nascimento[strcspn(banco_funcionarios[quantidade_funcionarios].nascimento, "\n")] = '\0';

    printf("Digite a rua do funcionario: ");
    fgets(banco_funcionarios[quantidade_funcionarios].endereco.rua, MAX, stdin);
    banco_funcionarios[quantidade_funcionarios].endereco.rua[strcspn(banco_funcionarios[quantidade_funcionarios].endereco.rua, "\n")] = '\0';

    printf("Digite o bairro do funcionario: ");
    fgets(banco_funcionarios[quantidade_funcionarios].endereco.bairro, MAX, stdin);
    banco_funcionarios[quantidade_funcionarios].endereco.bairro[strcspn(banco_funcionarios[quantidade_funcionarios].endereco.bairro, "\n")] = '\0';

    printf("Digite o numero da residencia do funcionario: ");
    scanf("%d", &banco_funcionarios[quantidade_funcionarios].endereco.numero);
    getchar();

    printf("Digite o CEP do funcionario(00000-000): ");
    fgets(banco_funcionarios[quantidade_funcionarios].endereco.CEP, MAX, stdin);
    banco_funcionarios[quantidade_funcionarios].endereco.CEP[strcspn(banco_funcionarios[quantidade_funcionarios].endereco.CEP, "\n")] = '\0';

    printf("Digite o salario do funcionario: R$");
    scanf("%lf", &banco_funcionarios[quantidade_funcionarios].salario);
    getchar();

    limpar();
    printf("\nFuncionario cadastrado com sucesso!\nPressione ENTER para continuar.\n\n");
    getchar();
    limpar();

}

void imprimir_lista(int quantidade_funcionarios, FUNCIONARIOS *banco_funcionarios){
    limpar();

    for(int i = 0; i < quantidade_funcionarios - 1; i++){
        int posicao_maior = i;

        for(int j = i + 1; j < quantidade_funcionarios; j++){
            if(banco_funcionarios[j].salario > banco_funcionarios[posicao_maior].salario){
                posicao_maior = j;
            }
        }

        FUNCIONARIOS temp = banco_funcionarios[i];
        banco_funcionarios[i] = banco_funcionarios[posicao_maior];
        banco_funcionarios[posicao_maior] = temp;
    }

    printf("----Lista de usuarios por SALARIO----\n\n");

    for(int i = 0; i < quantidade_funcionarios; i++){
        printf("Nome: %s\n", banco_funcionarios[i].nome);
        printf("Nascimento %s\n", banco_funcionarios[i].nascimento);
        printf("Rua: %s\n", banco_funcionarios[i].endereco.rua);
        printf("Bairro: %s\n", banco_funcionarios[i].endereco.bairro);
        printf("Numero da residencia %d\n", banco_funcionarios[i].endereco.numero);
        printf("CEP: %s\n", banco_funcionarios[i].endereco.CEP);
        printf("Salario %.2lf\n\n", banco_funcionarios[i].salario);

    }

    printf("Aperte ENTER para voltar.\n\n");
    getchar();
    limpar();

}

int main(){

    int opcao;
    FUNCIONARIOS *banco_funcionarios = NULL;
    int total_funcionarios = 0;
    while(1){
        opcao = menu_principal();

        while(opcao != 1 && opcao != 2 && opcao != 3){
            printf("Digite uma opcao valida!\n");
            opcao = menu_principal();
        }

        if(opcao == 1){
            getchar();
            total_funcionarios++;
            banco_funcionarios = realloc (banco_funcionarios, total_funcionarios * sizeof(FUNCIONARIOS));
            cadastrar_funcionario(total_funcionarios - 1, banco_funcionarios);
        }else if(opcao == 2){
            getchar();
            imprimir_lista(total_funcionarios, banco_funcionarios);
        }else{
            limpar();
            exit(0);
        }
        
    }

    free(banco_funcionarios);

    return 0;
}