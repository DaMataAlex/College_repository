#include "Lista2.h"

int main(void) {
    TipoCelula *L;
    TipoDado x;

    L = CriacaoLista();

    printf("Lista criada:\n");
    ImprimeL(L);

    printf("Digite valores inteiros para inserir (ordenado).\n");
    printf("Para terminar, digite -1.\n");

    printf("Digite um valor: ");
    x = LeituraDado();

    while (x != -1) {
        L = InsereOrdenadoL(L, x);

        printf("Lista (inicio -> fim): ");
        ImprimeL(L);

        printf("Lista (fim -> inicio): ");
        ImprimeLReverso(L);

        printf("Digite um valor: ");
        x = LeituraDado();
    }

    printf("Lista final (inicio -> fim): ");
    ImprimeL(L);

    printf("Lista final (fim -> inicio): ");
    ImprimeLReverso(L);

    LiberaLista(L);
    return 0;
}
