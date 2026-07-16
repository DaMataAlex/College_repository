#include "Lista.h"
#include <stdio.h>

int main() {
    TipoCelula *L;
    TipoDado x;

    L = CriacaoLista();

    printf("Lista criada: ");
    ImprimeL(L);

    printf("Digite um valor para remover: ");
    x = LeituraDado();

    L = RemocaoDadoL(L, x);

    printf("Lista apos remocao: ");
    ImprimeL(L);

    return 0;
}