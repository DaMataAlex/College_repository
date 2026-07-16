#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

typedef float TipoDado;

typedef struct Cell {
    TipoDado dado;
    struct Cell *seguinte;
} TipoCelula;

typedef struct {
    TipoCelula *cabeca, *queue;
} Fila;

Fila InicializarF(void);
int FilaVazia(Fila F);
int FilaCheia(Fila F);
int AcessarCabecaF(Fila F, TipoDado *pelem);
void DestruirF(Fila *pF);
void EsvaziarF(Fila *pF);
void InserirF(Fila *pF, TipoDado elem);
char RemoverF(Fila *pF, TipoDado *pelem);
void ImprimirFila(Fila F);

#endif
