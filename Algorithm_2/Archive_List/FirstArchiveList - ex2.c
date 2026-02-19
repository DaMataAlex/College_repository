#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *pArquivo = fopen("entrada.txt", "r");
    FILE *pCopia = fopen("copia.txt", "w");

    char c[1024];

    while(fgets(c,sizeof(c), pArquivo) != NULL){
        fputs(c, pCopia);
    }

    fclose(pArquivo);
    fclose(pCopia);
    pCopia = fopen("copia.txt", "r");

    int c2;

    printf("Arquivo copiado com sucesso!\n\n");
    while((c2 = fgetc(pCopia)) != EOF){
        printf("%c", c2);
    }
   
    fclose(pCopia);

    return 0;
}