#include "ImpDado.h";

void ImprimeL(TipoCelula *L) {
    TipoCelula *p;
    for (p = L; p != NULL; p = p->seguinte)
        ImpDado(p->dado);
    printf("\n");
}