#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){

    FILE *pArquivo = fopen("arq.txt", "r");

    char caracter;
    int ocorrencia;
    int c;

    printf("Digite o caracter cuja ocorrencia sera calculada no arquivo: ");
    scanf(" %c", &caracter);

    while((c = fgetc(pArquivo)) != EOF){
        c = tolower(c);
        if(c == caracter){
            ocorrencia++;
        }
    }

    printf("\nO caracter foi utilizado %d vezes no arquivo.\n", ocorrencia);
    fclose(pArquivo);

    return 0;

}