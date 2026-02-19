#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *pPalavras = fopen("palavras_computacao.txt", "r");

    int cinco_ou_mais = 0;
    int entre_tres_e_cinco = 0;
    char palavra[20];

    while(fscanf(pPalavras, "%19s", palavra) == 1){
        if(strlen(palavra) > 3 && strlen(palavra) < 5){
            entre_tres_e_cinco++;
        }else{
            cinco_ou_mais++;
        }
    }

    printf("Palavras com 5 ou mais letras: %d\n", cinco_ou_mais);
    printf("Palavras que possuem entre 3 e 5 letras: %d\n", entre_tres_e_cinco);

    fclose(pPalavras);

    return 0;
}