#include <stdio.h>
#include <stdlib.h>

typedef float TipoDado;

typedef struct Cell {
    TipoDado dado;
    struct Cell *seguinte;
} TipoCelula;

void ImpDado(TipoDado dado) {
    printf(" %.2f ", dado);
}

TipoDado LeituraDado(void) {
    TipoDado dado;
    scanf("%f", &dado);
    return dado;
}

TipoCelula* InsCabL(TipoCelula *antigaL, TipoDado dado) {
    TipoCelula *novaL;
    novaL = (TipoCelula*) malloc(sizeof(TipoCelula));
    novaL->dado = dado;
    novaL->seguinte = antigaL;
    return novaL;
}

TipoCelula* CriacaoListaInvertida(void) {
    char escolha;
    TipoDado dado;
    TipoCelula *L = NULL;

    printf("Deseja criar uma lista? (s = sim): ");
    escolha = getchar();
    getchar();

    while (escolha == 's') {
        printf("Fornecer um dado: ");
        dado = LeituraDado();
        getchar();
        L = InsCabL(L, dado);
        printf("Inserir mais uma celula? (s = sim): ");
        escolha = getchar();
        getchar();
    }
    return L;
}


void ImprimeL(TipoCelula *L) {
    TipoCelula *p;
    for (p = L; p != NULL; p = p->seguinte)
        ImpDado(p->dado);
    printf("\n");
}

TipoCelula* Concatenacao2L(TipoCelula *L1, TipoCelula *L2) {
    TipoCelula *p;

    if (L1 == NULL){
        return L2;
    }
    
    p = L1;

    while(p -> seguinte != NULL){
        p = p -> seguinte;
    }
    
    p->seguinte = L2;
    
    return L1;
}

int main(){

    TipoCelula *L1, *L2, *LConcat;

    printf("Criacao da primeira lista:\n");
    L1 = CriacaoListaInvertida();

    printf("\nPrimeira lista: ");
    ImprimeL(L1);

    printf("Criacao da segunda lista:\n");
    L2 = CriacaoListaInvertida();
    printf("\nSegunda lista: ");
    ImprimeL(L2);

    LConcat = Concatenacao2L(L1, L2);

    printf("Lista concatenada:\n");
    ImprimeL(LConcat);

    return 0;
}