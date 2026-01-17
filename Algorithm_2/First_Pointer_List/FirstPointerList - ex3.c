/*3. Escreva um programa que contenha duas variaveis inteiras. Compare seus enderecos
e exiba o maior endereco.*/

#include <stdio.h>

int main(){
    
    int a, b;

    printf("Digite o valor das duas variaveis:\n");
    scanf("%d %d", &a, &b);

    if(&a > &b){
        printf("Variavel de maior endereco: %d\nEndereco: %p\n", a, &a);
    }else{
        printf("Variavel de maior endereco: %d\nEndereco: %p\n", b, &b);
    }

    return 0;

}