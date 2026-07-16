#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* seguinte;
} No;

typedef No* Pilha;

void ImprimirPilha(Pilha P) {
    Pilha q;

    q = P;

    while (q != NULL) {
        printf("%d ", q->dado);
        q = q->seguinte;
    }

    printf("\n");
}

void Push(Pilha* P, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->seguinte = *P;
    *P = novo;
}
