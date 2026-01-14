/*7. Faca uma funcao que receba uma string e duas palavras, a primeira palavra sera 
a palavra a ser buscada na string e a segunda palavra a ser inserida no lugar da
primeira, mostre o resultado no programa principal.

Exemplo:
Original : O rato tem medo do gato. O gato tem medo do cachorro!
Primeira palavra ( a ser substituida): gato
Segunda palavra ( a substituir): sapo
Resultado: O rato tem medo do sapo. O sapo tem medo do cachorro!*/

#include <stdio.h>
#define max 100

void word_changer(char string[], char word1[], char word2[]){
    
    for(int i = 0; string[i] != '\0'; i++){
        for(int j = 0; word1[j] != '\0'; j++){
            if(string[i] == word1[j] && string[i+1] == word1[j+1] && string[i+2] == word1[j+2]){
                for(int w = 0; word1[w] != '\0'; w++){
                    string[i] = word2[w];
                }
            }
        }
    }
    printf("%s\n", string);

}

int main(){

    char string[max];
    char word1[max];
    char word2[max];

    fgets(string, max, stdin);
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == '\n'){
            string[i] = '\0';
        }
    }
    fgets(word1, max, stdin);
    for(int i = 0; word1[i] != '\0'; i++){
        if(word1[i] == '\n'){
            word1[i] = '\0';
        }
    }
    fgets(word2, max, stdin);
    for(int i = 0; word2[i] != '\0'; i++){
        if(word2[i] == '\n'){
            word2[i] = '\0';
        }
    }

    word_changer(string, word1, word2);

    return 0;

}