#include "fila.h"

int main(void) {
    Fila minhaFila;
    TipoDado valor;
    int opcao;
    char resultado;

    minhaFila = InicializarF();

    do {
        printf("\n----- MENU -----\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Ver inicio da fila\n");
        printf("4. Imprimir fila\n");
        printf("5. Esvaziar fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a enfileirar: ");
                scanf("%f", &valor);
                InserirF(&minhaFila, valor);
                printf("Valor enfileirado com sucesso.\n");
                break;

            case 2:
                resultado = RemoverF(&minhaFila, &valor);
                if (resultado == 0)
                    printf("Valor desenfileirado: %.2f\n", valor);
                else
                    printf("A fila esta vazia. Nada a desenfileirar.\n");
                break;

            case 3:
                resultado = AcessarCabecaF(minhaFila, &valor);
                if (resultado == 0)
                    printf("Inicio da fila: %.2f\n", valor);
                else
                    printf("A fila esta vazia.\n");
                break;

            case 4:
                printf("Conteudo da fila:\n");
                ImprimirFila(minhaFila);
                break;

            case 5:
                EsvaziarF(&minhaFila);
                printf("Fila esvaziada.\n");
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    DestruirF(&minhaFila);
    return 0;
}
