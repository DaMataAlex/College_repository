#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int main(){

    FILE *pEntrada = fopen("entrada.txt", "a");

    char linha[MAX];

    printf("Digite a string que sera escrita no arquivo:\n");
    fgets(linha, MAX, stdin);
    linha[strcspn(linha, "\n")] = '\0';
    printf("\n");

    fputs(linha, pEntrada);

    fclose(pEntrada);
    rewind(pEntrada);
    pEntrada = fopen("entrada.txt", "r");

    char c;

    while((c = fgetc(pEntrada)) != EOF){
        printf("%c", c);
    }

    fclose(pEntrada);

    return 0;

}