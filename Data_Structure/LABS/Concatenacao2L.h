TipoCelula* Concatenacao2L(TipoCelula *L1, TipoCelula *L2) {
    TipoCelula *p;

    if (L1 == NULL){
        return L2;
    }
    
    p = L1;

    while(p -> seguinte != NULL){
        p = p -> seguinte;
    }
    
    p->seguinte = L2;
    
    return L1;
}