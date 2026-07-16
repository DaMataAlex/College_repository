#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef int TipoDado;

typedef struct Cell {
    TipoDado dado;
    struct Cell *anterior;
    struct Cell *proximo;
} TipoCelula;

TipoCelula *CriacaoLista(void);
void ImprimeL(TipoCelula *L);
void ImprimeLReverso(TipoCelula *L);
void ImprimeDado(TipoDado dado);
TipoDado LeituraDado(void);
TipoCelula *InsereInicioL(TipoCelula *L, TipoDado dado);
TipoCelula *InsereFimL(TipoCelula *L, TipoDado dado);
void LiberaLista(TipoCelula *L);
TipoCelula *InsereOrdenadoL(TipoCelula *L, TipoDado dado);

#endif