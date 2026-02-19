#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *pEntrada = fopen("entrada.txt", "r");

    if(pEntrada == NULL){
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    char palavra[20];

    while(fscanf(pEntrada, "%19s", palavra) == 1){
        
        int tem_M = 0;

        for(int i = 0; palavra[i] != '\0'; i++){
            if(palavra[i] == 'm' || palavra[i] == 'M'){
                tem_M = 1;
                break;
            }
        }

        if(tem_M == 1){
            printf("%s ", palavra);
        }
    }

    fclose(pEntrada);

    return 0;

}