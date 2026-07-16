TipoCelula* CriacaoListaInvertida(void) {
    char escolha;
    TipoDado dado;
    TipoCelula *L = NULL;

    printf("Deseja criar uma lista? (o = sim): ");
    escolha = getchar();
    getchar();

    while (escolha == 'o') {
        printf("Fornecer um dado: ");
        dado = LeituraDado();
        getchar();
        L = InsCabL(L, dado);
        printf("Inserir mais uma celula? (o = sim): ");
        escolha = getchar();
        getchar();
    }
    return L;
}