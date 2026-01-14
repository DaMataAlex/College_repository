/*5. Sabendo que a funcao strlen conta a quantidade de caracteres que a string possui,
faca uma funcao que imite-a.*/

#include <stdio.h>
#define MAX 100

int counting_character(char string[]){
    int amount = 0;

    for(int i = 0; string[i] != '\0'; i++){
        amount = i;
    }

    return amount;
}

int main(){

    char string[MAX];
    fgets(string, MAX, stdin);

    int total_of_characters = counting_character(string);

    printf("A string possui %d caracteres.\n", total_of_characters);

    return 0;

}