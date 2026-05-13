#include <stdio.h>
#include "Functions.h"

int main(){

    int a, b;
    scanf("%d %d", &a, &b);

    int resultado = soma(a, b);

    printf("%d\n", resultado);

    return 0;
    
}