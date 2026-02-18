#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *pArquivo;
    int c;

    pArquivo = fopen("entrada.txt", "r");

    if (pArquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for ( int i =0; sizeof(pArquivo); i ++) {
        c = fgetc(pArquivo);
        if(c == EOF){
            break;
        }
        printf("%c", c);
    }

    fclose(pArquivo);

    return 0;
}