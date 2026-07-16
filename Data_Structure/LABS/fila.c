#include "fila.h"

Fila InicializarF(void) {
    Fila F;
    F.cabeca = NULL;
    F.queue = NULL;
    return F;
}

int FilaVazia(Fila F) {
    return (F.cabeca == NULL) ? 1 : 0;
}

int FilaCheia(Fila F) {
    return 0;
}

int AcessarCabecaF(Fila F, TipoDado *pelem) {
    if (FilaVazia(F))
        return 1;
    *pelem = F.cabeca->dado;
    return 0;
}

void DestruirF(Fila *pF) {
    TipoCelula *q;
    while (pF->cabeca != NULL) {
        q = pF->cabeca;
        pF->cabeca = pF->cabeca->seguinte;
        free(q);
    }
    pF->cabeca = NULL;
    pF->queue = NULL;
}

void EsvaziarF(Fila *pF) {
    DestruirF(pF);
}

void InserirF(Fila *pF, TipoDado elem) {
    TipoCelula *novo;
    novo = (TipoCelula*) malloc(sizeof(TipoCelula));
    novo->dado = elem;
    novo->seguinte = NULL;

    if (FilaVazia(*pF)) {
        pF->cabeca = novo;
        pF->queue = novo;
    } else {
        pF->queue->seguinte = novo;
        pF->queue = novo;
    }
}

char RemoverF(Fila *pF, TipoDado *pelem) {
    TipoCelula *q;

    if (FilaVazia(*pF))
        return 1;

    *pelem = pF->cabeca->dado;
    q = pF->cabeca;
    pF->cabeca = pF->cabeca->seguinte;
    free(q);

    if (pF->cabeca == NULL)
        pF->queue = NULL;

    return 0;
}

void ImprimirFila(Fila F) {
    TipoCelula *q;

    if (FilaVazia(F)) {
        printf("Fila vazia\n");
        return;
    }

    q = F.cabeca;
    while (q != NULL) {
        printf(" %.2f\n", q->dado);
        q = q->seguinte;
    }
}
