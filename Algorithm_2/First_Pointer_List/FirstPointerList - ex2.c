/*Escreva um programa que declare um inteiro, um real e um char, e ponteiros para
inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores
de cada variavel usando os ponteiros. Imprima os valores das variaveis antes e apos
a modificacao.*/

#include <stdio.h>
#include <stdlib.h>

void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

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
    scanf("%f", &b);
    printf("Digite o char:\n");
    scanf(" %c", &c);

    pa = &a;
    pb = &b;
    pc = &c;

    int backup_a = a;
    float backup_b = b;
    char backup_c = c;

    clear();

    printf("Digite os novos valores de a, b e c, respectivamente\n");

    scanf("%d", pa);
    scanf("%f", pb);
    scanf(" %c", pc);

    clear();

    printf("Antigos valores de a, b e c:\n");
    printf("a = %d\nb = %.1f\nc = %c\n\n", backup_a, backup_b, backup_c);
    printf("Novos valores de a, b e c:\n");
    printf("a = %d\nb = %.1f\nc = %c\n", a, b, c);

    return 0;

}