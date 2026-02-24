#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(){

    FILE *pArquivo = fopen("arq.txt", "r");

    char c;
    int vogais = 0;
    int consoantes = 0;

    while((c = fgetc(pArquivo)) != EOF){
        tolower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            vogais++;
        }else{
            if(isalpha(c)){
                consoantes++;
            }
        }
    }

    printf("O arquivo possui %d vogais e %d consoantes.\n", vogais, consoantes);
    fclose(pArquivo);

    return 0;
}