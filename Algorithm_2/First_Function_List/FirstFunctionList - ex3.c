/*3. Crie uma funcao que receba dois nomes e retorne quantas letras sao vogais. Use uma
outra funcao que verifica se eh uma vogal.*/

#include <stdio.h>
#include <ctype.h>

int is_vowel(char letter){
    
    if(tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'i' || tolower(letter) == 'o' || tolower(letter) == 'u'){
        return 1;
    }else{
        return 0;
    }
    
}

int how_many_vowels(char name1[20], char name2[20]){
    
    int total_vowels = 0;

    for(int i = 0; name1[i] != '\0'; i++){
        if(is_vowel(name1[i])){
        total_vowels++;
        }
    }

    for(int i = 0; name2[i] != '\0'; i++){
        if(is_vowel(name2[i])){
        total_vowels++;
        }
    }

    return total_vowels;
    
}

int main(){

    char name1[20];
    char name2[20];

    fgets(name1, sizeof(name1), stdin);
    fgets(name2, sizeof(name2), stdin);

    int vowals;
    vowals = how_many_vowels(name1, name2);

    printf("Os dois nomes possuem juntos %d vogais.\n", vowals);

    return 0;

}