#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha Inicializar() {
    return NULL;
}

int Empilhar(Pilha* P, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) return 0;
    novo->dado = valor;
    novo->seguinte = *P;
    *P = novo;
    return 1;
}

int Desempilhar(Pilha* P, int* valor) {
    if (*P == NULL) return 0;
    No* temp = *P;
    *valor = temp->dado;
    *P = temp->seguinte;
    free(temp);
    return 1;
}

int TopoPilha(Pilha P, int* valor) {
    if (P == NULL) return 0;
    *valor = P->dado;
    return 1;
}

void ImprimirPilha(Pilha P) {
    Pilha q = P;
    while (q != NULL) {
        printf("%d\n", q->dado);
        q = q->seguinte;
    }
    printf("\n");
}

void Esvaziar(Pilha* P) {
    No* temp;
    while (*P != NULL) {
        temp = *P;
        *P = temp->seguinte;
        free(temp);
    }
}

void Destruir(Pilha* P) {
    Esvaziar(P);
    *P = NULL;
}