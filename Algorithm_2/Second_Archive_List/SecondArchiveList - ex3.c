#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(){

    FILE *pArquivo = fopen("arq.txt", "r");

    char c;
    int vogais = 0;

    while((c = fgetc(pArquivo)) != EOF){
        tolower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            vogais++;
        }
    }

    printf("O arquivo possui %d vogais.\n", vogais);
    fclose(pArquivo);

    return 0;
}