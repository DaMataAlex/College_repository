#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *pArquivo;

    pArquivo = fopen("entrada.txt", "r");

    int contador_de_As = 0;
    long int tamanho_do_arquivo = 0;
    char c;


    while((c = fgetc(pArquivo))!= EOF){
        tamanho_do_arquivo++;
    }

    rewind(pArquivo);

    for(long int i = 0; i < tamanho_do_arquivo; i++){
        if((c = fgetc(pArquivo)) == 'a'){
            contador_de_As++;
        }
    }

    printf("O arquivo possui %d letras A\n", contador_de_As);

    fclose(pArquivo);

    return 0;

}