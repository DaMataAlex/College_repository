#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *pEntrada = fopen("entrada.txt", "r");

    char c;

    while((c = fgetc(pEntrada)) != EOF){
        printf("%c", c);
    }

    fclose(pEntrada);

    return 0;

}