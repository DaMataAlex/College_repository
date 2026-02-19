#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *pArquivo = fopen("entrada.txt", "r");

    int ContadorDeQuebraDeLinas = 0;
    char c;

    while((c = fgetc(pArquivo)) != EOF){
        if(c == '\n'){
            ContadorDeQuebraDeLinas++;
        }
    }

    printf("O texto tem %d linha(s).\n", ContadorDeQuebraDeLinas);
    fclose(pArquivo);
    
    return 0;

}