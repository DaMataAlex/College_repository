#include "Lista.h"

void ImpDado(TipoDado dado) {
    printf(" %.2f ", dado);
}

TipoDado LeituraDado() {
    TipoDado dado;
    scanf("%f", &dado);
    return dado;
}

TipoCelula* InsFimL(TipoCelula *L, TipoDado dado) {
    TipoCelula *p, *novo;
    novo = (TipoCelula*) malloc(sizeof(TipoCelula));
    novo->dado = dado;
    novo->seguinte = NULL;
    if (L == NULL)
        return novo;
    for (p = L; p->seguinte != NULL; p = p->seguinte)
        {}
    p->seguinte = novo;
    return L;
}

TipoCelula* CriacaoLista() {
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
        L = InsFimL(L, dado);
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

TipoCelula* RemocaoDadoL(TipoCelula *L, TipoDado dado) {
    TipoCelula *p, *seguinte, *pL;

    p = L;

    if (p == NULL)
        return L;

    if (p->dado == dado) {
        pL = p->seguinte;
        free(p);
        return pL;
    }

    seguinte = p->seguinte;

    while (seguinte != NULL && seguinte->dado != dado) {
        p = p->seguinte;
        if (p != NULL)
            seguinte = p->seguinte;
    }

    if (seguinte != NULL && seguinte->dado == dado) {
        p->seguinte = seguinte->seguinte;
        free(seguinte);
    }

    return L;
}