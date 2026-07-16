#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha minhaPilha;
    int valor, resultado, opcao;

    minhaPilha = Inicializar();

    do {
        printf("\n----- MENU -----\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Ver topo da pilha\n");
        printf("4. Imprimir pilha\n");
        printf("5. Esvaziar pilha\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a empilhar: ");
                scanf("%d", &valor);
                Empilhar(&minhaPilha, valor);
                printf("Valor empilhado com sucesso.\n");
                break;

            case 2:
                resultado = Desempilhar(&minhaPilha, &valor);
                if (resultado != 0)
                    printf("Valor desempilhado: %d\n", valor);
                else
                    printf("A pilha esta vazia. Nada a desempilhar.\n");
                break;

            case 3:
                resultado = TopoPilha(minhaPilha, &valor);
                if (resultado != 0)
                    printf("Topo da pilha: %d\n", valor);
                else
                    printf("A pilha esta vazia.\n");
                break;

            case 4:
                printf("Conteudo da pilha:\n");
                ImprimirPilha(minhaPilha);
                break;

            case 5:
                Esvaziar(&minhaPilha);
                printf("Pilha esvaziada.\n");
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    Destruir(&minhaPilha);
    return 0;
}