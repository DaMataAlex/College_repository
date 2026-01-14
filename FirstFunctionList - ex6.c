/*6. Faca uma funcao que receba uma string e dobre todas as palavras existentes, mostre
o resultado no programa principal. Exemplo: Original : O rato roeu a roupa do rei
de roma Resultado: O O rato rato roeu roeu a a roupa roupa do do rei rei de de
roma roma*/

#include <stdio.h>
#include <string.h>

#define max 100

void tongue_twister(char phrase[]) {
    char twister[max * 2] = "";
    char tongue[max] = "";
    int w = 0;

    for (int i = 0; phrase[i] != '\0'; i++) {
        if (phrase[i] != ' ' && phrase[i] != '\n') {
            tongue[w++] = phrase[i];
        } else {
            tongue[w] = '\0';

            strcat(twister, tongue);
            strcat(twister, " ");
            strcat(twister, tongue);
            strcat(twister, " ");

            w = 0;
        }
    }

    if (w > 0) {
        tongue[w] = '\0';
        strcat(twister, tongue);
        strcat(twister, " ");
        strcat(twister, tongue);
    }

    printf("%s\n", twister);
}

int main() {
    char string[max];

    fgets(string, max, stdin);

    tongue_twister(string);

    return 0;
}