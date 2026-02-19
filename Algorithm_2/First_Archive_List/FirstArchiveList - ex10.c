#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *pArquivo;

    pArquivo = fopen("entrada.txt", "r");

    int contador_de_erres = 0;
    long int tamanho_do_arquivo = 0;
    char c;


    while((c = fgetc(pArquivo))!= EOF){
        tamanho_do_arquivo++;
    }

    rewind(pArquivo);

    for(long int i = 0; i < tamanho_do_arquivo; i++){
        if((c = fgetc(pArquivo)) == 'r' || (c = fgetc(pArquivo)) == 'R'){
            contador_de_erres++;
        }
    }

    printf("O arquivo possui %d letras R\n", contador_de_erres);

    fclose(pArquivo);

    return 0;

}