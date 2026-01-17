/*4. Escreva um programa que contenha duas variaveis inteiras. Leia essas variaveis do
teclado. Em seguida, compare seus enderecos e exiba o conteudo do maior endereco.*/

#include <stdio.h>
 
void main(){

    int a, b;
    printf("Digite duas variaveis inteiras:\n");
    scanf("%d %d", &a, &b);

    if(&a > &b){
        printf("Variavel de maior endereco: %d\n", a);
    }else{
        printf("Variavel de maior endereco: %d\n", b);
    }

}