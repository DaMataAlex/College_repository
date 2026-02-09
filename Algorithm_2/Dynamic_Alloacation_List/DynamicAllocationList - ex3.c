#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

//structs
typedef struct{
    char nome[MAX];
    char nascimento[10];
    char rua[MAX];
    char bairro[MAX];
    int numero_endereco;
    char CEP[10];
    double salario;
}funcionarios;

//funcoes
void limpar_terminal(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int menu_principal(){
    printf("===BANCO DE FUNCIONARIOS===\n\n");
    printf("Escolha uma das opcoes abaixo\n");
    printf("1 - Listar todos os funcionarios.\n");
    printf("2 - Adicionar novo usuario.\n");
    printf("3 - Sair do programa.\n\n");

    int opcao;
    scanf("%d", &opcao);

    while(opcao < 1 || opcao > 4){
        limpar_terminal();
        printf("===BANCO DE FUNCIONARIOS===\n");
        printf("Insira uma opcao valida!\n\n");
        printf("Escolha uma das opcoes abaixo\n");
        printf("1 - Listar todos os funcionarios.\n");
        printf("2 - Adicionar novo usuario.\n");
        printf("3 - Sair do programa.");

        scanf("%d", &opcao);
    }

    limpar_terminal();
    return opcao;

}

void cadastrar_funcionario(funcionarios *novo_funcionario){
    printf("Digite o nome do usuario: ");
    getchar();
    fgets(novo_funcionario->nome, MAX, stdin);
    novo_funcionario->nome[strcspn(novo_funcionario->nome,"\n")] = '\0';

    printf("Digite a data de nascimento do funcionario: ");
    fgets(novo_funcionario->nascimento, 10, stdin);
    novo_funcionario->nascimento[strcspn(novo_funcionario->nascimento,"\n")] = '\0';

    printf("Digite o nome da rua do funcionario: ");
    fgets(novo_funcionario->rua, MAX, stdin);
    novo_funcionario->rua[strcspn(novo_funcionario->rua,"\n")] = '\0';

    printf("Digite o nome do bairro do funcionario: ");
    fgets(novo_funcionario->bairro, MAX, stdin);
    novo_funcionario->bairro[strcspn(novo_funcionario->bairro, "\n")] = '\0';

    printf("Digite o numero de endereco do funcionario: ");
    scanf("%d", &novo_funcionario->numero_endereco);

    printf("Digite o CEP do funcionario: ");
    getchar();
    fgets(novo_funcionario->CEP, 10, stdin);
    novo_funcionario->CEP[strcspn(novo_funcionario->CEP, "\n")] = '\0';

    printf("Digite o salario do funcionario: ");
    scanf("%lf", &novo_funcionario->salario);

    limpar_terminal();
    printf("\nFuncionario cadastrado com sucesso!\n");
    getchar();
    getchar();
    limpar_terminal();

}

void listar_funcionarios(funcionarios *banco_funcionarios, int qtd){
    getchar();
    limpar_terminal();
    printf("Atualmente a empresa possui %d funcionarios.\n", qtd);

    for(int i = 0; i < qtd; i++){
        printf("\n%s\n", banco_funcionarios[i].nome);
        printf("%s\n", banco_funcionarios[i].nascimento);
        printf("%s\n", banco_funcionarios[i].rua);
        printf("%s\n", banco_funcionarios[i].bairro);
        printf("%d\n", banco_funcionarios[i].numero_endereco);
        printf("%s\n", banco_funcionarios[i].CEP);
        printf("%lf\n", banco_funcionarios[i].salario);
    }
    printf("\n");
    getchar();

}

int main(){

    funcionarios *banco_funcionarios = NULL;
    int input;
    int quantidade_de_funcionarios = 0;

    while(1){
        input = menu_principal();

        if(input == 2){
            quantidade_de_funcionarios++;
            funcionarios *ref = realloc(banco_funcionarios, quantidade_de_funcionarios * sizeof(funcionarios));

            //mata o programa caso nao consigo alocar mais memoria
            if(ref == NULL){
                printf("Erro ao alocar memoria!\n");
                exit(1);
            }
            
            banco_funcionarios = ref;
            cadastrar_funcionario(&banco_funcionarios[quantidade_de_funcionarios - 1]);

        }else if(input == 1){
            listar_funcionarios(banco_funcionarios, quantidade_de_funcionarios);
            limpar_terminal();

        }else{
            break;
        }
    }

    return 0;

}