#include <stdio.h>
#include <stdlib.h>

int main(){

    int n = 1;
    int *vetor = (int*) malloc(n * sizeof(int));

    while((scanf("%d", &vetor[n])) != 0){
        vetor = realloc(vetor, (n + 1) * sizeof(int));
        n += 1;
    }

    for(int i = 0; vetor[i] != 0; i++){
        printf("%d", vetor[i]);

        if(vetor[i + 1] != 0){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    
    return 0;

}