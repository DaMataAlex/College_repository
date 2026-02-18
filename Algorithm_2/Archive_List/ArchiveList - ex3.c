#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *pArquivo;

    pArquivo = fopen("entrada.txt", "r");

    int c;
    int contador = 0;
    

    for(int i = 0; i < sizeof(pArquivo); i++){
        if(*pArquivo == 'a'){
            contador++;
        }
    }

    printf("O arquivo possui %d letras a,\n", contador);

    fclose(pArquivo);

    return 0;

}