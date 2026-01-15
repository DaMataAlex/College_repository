/*Escreva um programa que declare um inteiro, um real e um char, e ponteiros para
inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores
de cada variavel usando os ponteiros. Imprima os valores das variaveis antes e apos
a modificacao.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int a;
    float b;
    char c;
    int *pa;
    float *pb;
    char *pc;

    printf("Digite o valor do inteiro:\n");
    scanf("%d", &a);
    printf("Digite o valor do real:\n");
    scanf("%d", &b);
    printf("Digite o char:\n");
    scanf("%d", &c);

    pa = &a;
    pb = &b;
    pc = &c;

    return 0;

}