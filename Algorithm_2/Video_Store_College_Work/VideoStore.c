#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define max 50

int menu(){
    printf("\n\nPLATAFORMA DE GERENCIAMENTO DE ASSINATURAS\n\n");
    printf("Escolha umas das seguintes opcoes:\n");
    printf("1 - Cadastrar um novo usuario.\n");
    printf("2 - Cadastrar um novo servico de streaming.\n");
    printf("3 - Consultar dados de um usuario.\n");
}

typedef struct {
    int dia;
    int mes;
    int ano;

}DATAS;

typedef struct {
    char nome[max];
    char cpf[14]; //contandos hifens e pontos
    int id_usuario;
    char phone[13]; //contando parenteses e hifens
    char email[max];

}USUARIOS;

typedef struct {
    char nome_plataforma[max];
    int id_plataforma;
    char categoria[max];
    float preco;
    char site_url[max];

}PLATAFORMAS;

typedef struct {
    int id_usuario;
    int id_plataforma;
    int id_assinatura;
    DATAS data_inicio_assinatura;
    DATAS data_proxima_cobranca;
    int ativa;
    float valor_pago;

}ASSINATURAS;

int main(){

    menu();

    return 0;

}
