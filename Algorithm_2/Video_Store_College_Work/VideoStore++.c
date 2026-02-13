#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
#define MAX_CHAR 50


//=========================
//  PRINCIPAIS  STRUCTS
//=========================
typedef struct {
  char nome[MAX];
  char cpf[15]; //campo unico da struct; 15 contandos hifens e pontos
  long int id_usuario; 
  char phone[14]; //contando parenteses e hifens
  char email[MAX];
    
}USUARIOS;

typedef struct {
  char nome_plataforma[MAX]; //campo unico da struct
  long int id_plataforma;
  char categoria[MAX];
  float preco;
  char site_url[MAX];

}PLATAFORMAS;

typedef struct {
  USUARIOS usuario_assinante;
  PLATAFORMAS plataforma_contratada;
  int id_assinatura; //campo unico da struct
  int ativa;
  float valor_pago;

}ASSINATURAS;


//=========================
//   FUNCOES AUXILIARES
//=========================
void LimparTerminal(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void LimparBuffer(){
    int c;

    while((c = getchar()) != '\n' && c != EOF);
}

char *ValidarEFormatarCpf(char cpf[15]){
    //validando cpf
    //formato: 000.000.000-00
    while(cpf[3] != '.' && cpf[7] != '.' && cpf[11] != '-' && strlen(cpf) != 15){
        LimparTerminal();
        printf("Por favor, insira um CPF valido!\n");
        printf("(000.000.000-00)\n\n");
        fgets(cpf, 15, stdin);
    }
    cpf[strcspn(cpf, "\n")] = '\0';

    LimparTerminal();

    char *pCPF = cpf;
    return pCPF;
}

char *ValidarEFormatarTelefone(char telefone[12]){
    char telefone_formatado[15];
    int todos_digitos = 0;

    //validando o telefone
    for(int i = 0; i < 11; i++){
        if(isdigit(telefone[i])){
            todos_digitos++;
        }
    }

    while(todos_digitos != 11){
        todos_digitos = 0;
        LimparTerminal();
        printf("Digite o telefone no formato valido!\n(Somente numeros)\n\n");
        fgets(telefone, 12, stdin);

        for(int i = 0; i < 11; i++){
            if(isdigit(telefone[i])){
                todos_digitos++;
            }
        }
    }
    LimparTerminal();
    
    int i = 0; //indice do telefone que a gente tem
    int j = 0; //indice do telefone que a gente vai montar

    while(i < 11){

        if(j == 0){
            telefone_formatado[j] = '(';
            telefone_formatado[j++] = telefone[i++];
        }else if(j == 2){
            telefone_formatado[j++] = ')';
        }else if(j == 8){
            telefone_formatado[j++] = '-';
        }else{
            telefone_formatado[j++] = telefone[i++];
        }
    }

    telefone_formatado[j] = '\0';

    char *pTelefoneFormatado = telefone_formatado;
    return pTelefoneFormatado;

}

void RetomarMenu(USUARIOS *pBancoUsuarios, PLATAFORMAS *pBancoPlataformas, ASSINATURAS *pBancoAssinaturas, int *total_clientes, int *total_plataformas){
    LimparTerminal();

    //retomar menu do cadastro de usuarios
    if(pBancoPlataformas == NULL && pBancoAssinaturas == NULL && total_plataformas == NULL){
        if(pBancoUsuarios[*total_clientes].phone[0] == '\0'){
            printf("-- Cadastro de clientes --\n\n");
            printf("Digite o nome do cliente: ");
            printf("%s\n", pBancoUsuarios[*total_clientes].nome);
            printf("Digite o CPF do cliente (000.000.000-00): ");
            printf("%s\n", pBancoUsuarios[*total_clientes].cpf);

        }else if(pBancoUsuarios[*total_clientes].email[0] == '\0'){
            printf("-- Cadastro de clientes --\n\n");
            printf("Digite o nome do cliente: ");
            printf("%s\n", pBancoUsuarios[*total_clientes].nome);
            printf("Digite o CPF do cliente (000.000.000-00): ");
            printf("%s\n", pBancoUsuarios[*total_clientes].cpf);
            printf("Digite o telefone do usuario: ");
            printf("%s\n", pBancoUsuarios[*total_clientes].phone);
        }
    }
}


//--- GERENCIAMENTO DE CLIENTES ---
void CadastrarNovoCliente(USUARIOS *pBancoUsuarios, int *total_clientes){

    //cadastro do nome
    printf("-- Cadastro de clientes --\n\n");
    printf("Digite o nome do cliente: ");
    fgets(pBancoUsuarios[*total_clientes].nome, MAX_CHAR, stdin);
    pBancoUsuarios[*total_clientes].nome[strcspn(pBancoUsuarios[*total_clientes].nome, "\n")] = '\0';

    //cadastro do cpf
    printf("Digite o CPF do cliente (000.000.000-00): ");
    fgets(pBancoUsuarios[*total_clientes].cpf, 15, stdin);
    char *pCPF = ValidarEFormatarCpf(pBancoUsuarios[*total_clientes].cpf);
    strcpy(pBancoUsuarios[*total_clientes].cpf, pCPF);
    RetomarMenu(pBancoUsuarios, NULL, NULL, total_clientes, NULL);
    LimparBuffer();

    //cadastro do telefone
    printf("Digite o telefone do usuario: ");
    char telefone[12], *pTelefoneFormatado;
    fgets(telefone, 12, stdin);
    pTelefoneFormatado = ValidarEFormatarTelefone(telefone);
    strcpy(pBancoUsuarios[*total_clientes].phone, pTelefoneFormatado);
    RetomarMenu(pBancoUsuarios, '\0', '\0', total_clientes, NULL);
    LimparBuffer();

    printf("Digite o Email do usuario: ");

}


//--- MENUS ---
int MenuPrincipal(int opcao){
    printf("== Plataforma de Gerenciamento de Assinaturas ==\n\n");
    printf("1 - Gerenciamento de clientes.\n");
    printf("2 - Gerenciamento de plataformas.\n");
    printf("3 - Gerenciamento de assinaturas.\n");
    printf("4 - Sair.\n\n");

    scanf("%d", &opcao);
    getchar();//consumindo a quebra de linha

    while(opcao < 1 || opcao > 4){
        LimparTerminal();
        printf("Digite uma opcao valida!\n");
        return MenuPrincipal(opcao);
    }

    LimparTerminal();
    return opcao;
}

int GerenciamentoDeClientes(){
    printf("-- Gerenciamento de clientes --\n\n");
    printf("1 - Cadastrar um novo cliente.\n");
    printf("2 - Buscar um cliente.\n");
    printf("3 - Alterar dados de um cliente.\n");
    printf("4 - Excluir um cliente;\n");
    printf("5 - Voltar\n\n");

    int opcao;
    scanf("%d", &opcao);
    getchar();//consumindo a quebra de linha

    while(opcao < 1 || opcao > 5){
        LimparTerminal();
        printf("Escolha uma opcao valida!\n");
        return GerenciamentoDeClientes();
    }
    
    LimparTerminal();

    return opcao;
    
}

int main(){

    int total_clientes = 0;

    int *pTotalClientes = &total_clientes;
    USUARIOS *pBancoUsuarios = (USUARIOS*) calloc(MAX, sizeof(USUARIOS));


    while(1){
        int opcao = MenuPrincipal(opcao);

        if(opcao == 1){
            opcao = GerenciamentoDeClientes();
            if(opcao == 1){
                (*pTotalClientes)++;
                pBancoUsuarios = realloc (pBancoUsuarios, *pTotalClientes * sizeof(USUARIOS));
                CadastrarNovoCliente(pBancoUsuarios, pTotalClientes);
            }
        }else if(opcao == 2){
            exit(0);
        }else if(opcao == 3){
            exit(0);
        }else{
            exit(0);
        }
    }

    return 0;
}