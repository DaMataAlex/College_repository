TipoCelula* InsCabL(TipoCelula *antigaL, TipoDado dado) {
    TipoCelula *novaL;
    novaL = (TipoCelula*) malloc(sizeof(TipoCelula));
    novaL->dado = dado;
    novaL->seguinte = antigaL;
    return novaL;
}