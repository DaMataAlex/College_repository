#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef float TipoDado;

typedef struct Cell {
    TipoDado dado;
    struct Cell *seguinte;
} TipoCelula;

void ImpDado(TipoDado dado);
TipoDado LeituraDado(void);
TipoCelula* InsFimL(TipoCelula *L, TipoDado dado);
TipoCelula* CriacaoLista(void);
void ImprimeL(TipoCelula *L);
TipoCelula* RemocaoDadoL(TipoCelula *L, TipoDado dado);

#endif