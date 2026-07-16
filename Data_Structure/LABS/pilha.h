#ifndef PILHA_H
#define PILHA_H

typedef struct No {
    int dado;
    struct No* seguinte;
} No;

typedef No* Pilha;

Pilha Inicializar();
int Empilhar(Pilha* P, int valor);
int Desempilhar(Pilha* P, int* valor);
int TopoPilha(Pilha P, int* valor);
void ImprimirPilha(Pilha P);
void Esvaziar(Pilha* P);
void Destruir(Pilha* P);

#endif