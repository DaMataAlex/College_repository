#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *pEntrada = fopen("entrada.txt", "r");
    FILE *pSaida = fopen("saida.txt", "w");

    char copiador;

    while((copiador = fgetc(pEntrada)) != EOF){
        if(copiador == 'e' || copiador == 'E'){
            fputc('3', pSaida);
        }else{
            fputc(copiador, pSaida);
        }
    }

    fclose(pEntrada);
    fclose(pSaida);
    pSaida = fopen("saida.txt", "r");

    while((copiador = fgetc(pSaida)) != EOF){
        printf("%c", copiador);
    }

    fclose(pSaida);

    return 0;
}