#include "Lista2.h"

TipoCelula *CriacaoLista(void) {
    return NULL;
}

void ImprimeDado(TipoDado dado) {
    printf("%d", dado);
}

TipoDado LeituraDado(void) {
    TipoDado x;
    scanf("%d", &x);
    return x;
}

void ImprimeL(TipoCelula *L) {
    TipoCelula *p = L;
    printf("[ ");
    while (p != NULL) {
        ImprimeDado(p->dado);
        if (p->proximo != NULL) printf(" <-> ");
        p = p->proximo;
    }
    printf(" ]\n");
}

void ImprimeLReverso(TipoCelula *L) {
    TipoCelula *p = L;
    if (p == NULL) {
        printf("[ ]\n");
        return;
    }
    while (p->proximo != NULL)
        p = p->proximo;
    printf("[ ");
    while (p != NULL) {
        ImprimeDado(p->dado);
        if (p->anterior != NULL) printf(" <-> ");
        p = p->anterior;
    }
    printf(" ]\n");
}

TipoCelula *InsereInicioL(TipoCelula *L, TipoDado dado) {
    TipoCelula *novo = (TipoCelula*) malloc(sizeof(TipoCelula));
    if (novo == NULL) {
        printf("Erro: sem memoria.\n");
        return L;
    }
    novo->dado = dado;
    novo->anterior = NULL;
    novo->proximo = L;
    if (L != NULL)
        L->anterior = novo;
    return novo;
}

TipoCelula *InsereFimL(TipoCelula *L, TipoDado dado) {
    TipoCelula *novo = (TipoCelula*) malloc(sizeof(TipoCelula));
    TipoCelula *p;
    if (novo == NULL) {
        printf("Erro: sem memoria.\n");
        return L;
    }
    novo->dado = dado;
    novo->proximo = NULL;
    novo->anterior = NULL;
    if (L == NULL)
        return novo;
    p = L;
    while (p->proximo != NULL)
        p = p->proximo;
    p->proximo = novo;
    novo->anterior = p;
    return L;
}

void LiberaLista(TipoCelula *L) {
    TipoCelula *p = L;
    TipoCelula *prox;
    while (p != NULL) {
        prox = p->proximo;
        free(p);
        p = prox;
    }
}

TipoCelula *InsereOrdenadoL(TipoCelula *L, TipoDado dado) {
    TipoCelula *anterior, *novo, *proximo;

    novo = (TipoCelula*) malloc(sizeof(TipoCelula));
    if (novo == NULL) {
        printf("Erro: sem memoria.\n");
        return L;
    }
    novo->dado = dado;

    /* lista vazia */
    if (L == NULL) {
        novo->proximo = NULL;
        novo->anterior = NULL;
        return novo;
    }

    /* inserir no inicio */
    if (dado < L->dado) {
        novo->anterior = NULL;
        novo->proximo = L;
        L->anterior = novo;
        return novo;
    }

    /* demais casos */
    anterior = L;
    proximo = anterior->proximo;

    while (proximo != NULL && proximo->dado < dado) {
        anterior = proximo;
        proximo = proximo->proximo;
    }

    if (proximo == NULL) {
        /* inserir no fim */
        anterior->proximo = novo;
        novo->anterior = anterior;
        novo->proximo = NULL;
    } else {
        /* inserir no meio */
        anterior->proximo = novo;
        novo->anterior = anterior;
        novo->proximo = proximo;
        proximo->anterior = novo;
    }

    return L;
}
