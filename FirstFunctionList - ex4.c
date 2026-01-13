/*4. Sabendo que a funcao strcat concatena duas strings, faca uma funcao que imite-a.*/

#include <stdio.h>
#include <string.h>

void hand_made_concatenation(char string1[], char string2[]) {
    int i = 0;
    int j = 0;

    while (string1[i] != '\n') {
        i++;
    }

    while (string2[j] != '\0') {
        string1[i] = string2[j];
        i++;
        j++;
    }

    string1[i - 1] = '\0';
}

int main() {
    char string1[20];
    char string2[10];

    fgets(string1, sizeof(string1), stdin);
    fgets(string2, sizeof(string2), stdin);

    hand_made_concatenation(string1, string2);

    printf("%s\n", string1);

    return 0;
}
