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
  char cpf[15]; //campo unico da struct
  long int id_usuario;
  char phone[15];
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

char *ValidarEFormatarTelefone(char telefone[15]){
    //validando telefone
    //formato: (00)90000-0000
    while(telefone[0] != '(' && telefone[3] != ')' && telefone[9] != '-' && strlen(telefone) != 15){
        LimparTerminal();
        printf("Por favor, insira um telefone valido!\n");
        printf("(00)90000-0000\n\n");
        fgets(telefone, 15, stdin);
    }
    telefone[strcspn(telefone, "\n")] = '\0';

    LimparTerminal();

    char *pTelefone = telefone;
    return pTelefone;

}

char *ValidarEFormatarEmail(char email[MAX_CHAR]){
    //validando email
    //precisa ter um @
    int arroba = 0;

    while(1){
        for(int i = 0 ; i < strlen(email); i++){
            if(email[i] == '@'){
                arroba = 1;
                break;
            }
        }

        if(arroba  == 1){
            break;
        }

        LimparTerminal();
        printf("Por favor, insira um Email valido!\n");
        fgets(email, 15, stdin);
        
    }

    email[strcspn(email, "\n")] = '\0';

    LimparTerminal();

    char *pEmail = email;
    return pEmail;

}

void RetomarMenu(USUARIOS *pBancoUsuarios, PLATAFORMAS *pBancoPlataformas, ASSINATURAS *pBancoAssinaturas, int *total_clientes, int *total_plataformas){
    LimparTerminal();

    //retomar menu do cadastro de usuarios
    if(pBancoPlataformas == NULL && pBancoAssinaturas == NULL && total_plataformas == NULL){
        if(pBancoUsuarios[*total_clientes].phone[0] == '\0'){
            printf("-- Cadastro de clientes --\n\n");
            printf("Digite o nome do cliente: ");
            printf("%s\n", pBancoUsuarios[*total_clientes].nome);
            printf("Digite o CPF do cliente: ");
            printf("%s\n", pBancoUsuarios[*total_clientes].cpf);

        }else if(pBancoUsuarios[*total_clientes].email[0] == '\0'){
            printf("-- Cadastro de clientes --\n\n");
            printf("Digite o nome do cliente: ");
            printf("%s\n", pBancoUsuarios[*total_clientes].nome);
            printf("Digite o CPF do cliente: ");
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
    printf("Digite o telefone do usuario (00)90000-0000: ");
    fgets(pBancoUsuarios[*total_clientes].phone, 15, stdin);
    char *pTelefoneFormatado = ValidarEFormatarTelefone(pBancoUsuarios[*total_clientes].phone);
    strcpy(pBancoUsuarios[*total_clientes].phone, pTelefoneFormatado);
    RetomarMenu(pBancoUsuarios, NULL, NULL, total_clientes, NULL);
    LimparBuffer();

    //cadastro email
    printf("Digite o Email do usuario: ");
    fgets(pBancoUsuarios[*total_clientes].email, MAX_CHAR, stdin);
    char *pEmailFormatado = ValidarEFormatarEmail(pBancoUsuarios[*total_clientes].email);
    strcpy(pBancoUsuarios[*total_clientes].email, pEmailFormatado);
    RetomarMenu(pBancoUsuarios, NULL, NULL, total_clientes, NULL);

    //cadastrando o id do usuario
    pBancoUsuarios[*total_clientes].id_usuario = 1000 + *total_clientes;

    //mensagem de cadastro concluido
    LimparTerminal();
    printf("Usuario cadastrado com sucesso!\n");
    printf("Id do usuario: %d\n\n", pBancoUsuarios[*total_clientes].id_usuario);
    getchar();
    LimparTerminal();
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
                pBancoUsuarios = realloc (pBancoUsuarios, (total_clientes + 1) * sizeof(USUARIOS));
                CadastrarNovoCliente(pBancoUsuarios, pTotalClientes);
                total_clientes++;
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