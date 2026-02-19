#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *pEntrada = fopen("entrada.txt", "r");
    FILE *pPalavras = fopen("palavras_computacao.txt", "r");

    FILE *pEntradaCopia = fopen("entradaCOPIA.txt", "w");
    FILE *pPalavrasCopia = fopen("palavras_computacaoCOPIA.txt", "w");

    int c;

    while((c = fgetc(pEntrada)) != EOF){
        fputc(c, pEntradaCopia);
    }


    while((c = fgetc(pPalavras)) != EOF){
        fputc(c, pPalavrasCopia);
    }

    fclose(pEntrada);
    fclose(pEntradaCopia);
    fclose(pPalavras);
    fclose(pPalavrasCopia);

    return 0;

}