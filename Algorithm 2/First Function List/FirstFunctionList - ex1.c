/*1. Desenvolva um programa principal (main) que devera ler o dia, mess e ano. Faca
uma funcao receba esses valores e retorne se os valores fornecidos formam uma data
valida. Se for valida, faca uma outra funcao que recebe esta mesma data e imprime
a data como ilustrado a seguir: Entrada: 18/03/2025 Saida: 18 de marco de 2025.*/

#include <stdio.h>
#include <stdlib.h>

int validation(int d, int m, int y){
    int valid = 1;

    if(d <= 0 || d > 31){
        valid = 0;
    }

    if(m <= 0 || m > 12){
        valid = 0;
    }

    return valid;
}

void print(int d, int m, int y){

    if(m == 1){
        printf("%d de Janeiro de %d ", d, y);
        if(y <= 0){
            printf("A.C.\n");
        }else{
            printf("D.C.\n");
        }
    }
    if(m == 2){
        printf("%d de Fevereiro de %d ", d, y);
        if(y <= 0){
            printf("A.C.\n");
        }else{
            printf("D.C.\n");
        }
    }
    if(m == 3){
        printf("%d de Marco de %d ", d, y);
        if(y <= 0){
            printf("A.C.\n");
        }else{
            printf("D.C.\n");
        }
    }
    if(m == 4){
        printf("%d de Abril de %d ", d, y);
        if(y <= 0){
            printf("A.C.\n");
        }else{
            printf("D.C.\n");
        }
    }
    if(m == 5){
        printf("%d de Maio de %d ", d, y);
        if(y <= 0){
            printf("A.C.\n");
        }else{
            printf("D.C.\n");
        }
    }
    if(m == 6){
        printf("%d de Junho de %d ", d, y);
        if(y <= 0){
            printf("A.C.\n");
        }else{
            printf("D.C.\n");
        }
    }
    if(m == 7){
        printf("%d de Julho de %d ", d, y);
        if(y <= 0){
            printf("A.C.\n");
        }else{
            printf("D.C.\n");
        }
    }
    if(m == 8){
        printf("%d de Agosto de %d ", d, y);
        if(y <= 0){
            printf("A.C.\n");
        }else{
            printf("D.C.\n");
        }
    }
    if(m == 9){
        printf("%d de Setembro de %d ", d, y);
        if(y <= 0){
            printf("A.C.\n");
        }else{
            printf("D.C.\n");
        }
    }
    if(m == 10){
        printf("%d de Outubro de %d ", d, y);
        if(y <= 0){
            printf("A.C.\n");
        }else{
            printf("D.C.\n");
        }
    }
    if(m == 11){
        printf("%d de Novembro de %d ", d, y);
        if(y <= 0){
            printf("A.C.\n");
        }else{
            printf("D.C.\n");
        }
    }
    if(m == 12){
        printf("%d de Dezembro de %d ", d, y);
        if(y <= 0){
            printf("A.C.\n");
        }else{
            printf("D.C.\n");
        }
    }
}

int main(){

    int day, month, year;
    scanf("%d/%d/%d", &day, &month, &year);

    int inspection;
    if((inspection = validation(day, month, year)) == 1){
        print(day, month, year);
    }else{
        printf("Os dados nao formam uma data valida\n");
    }

    return 0;
}
