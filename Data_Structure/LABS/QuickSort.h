#include <stdio.h>

int Particionamento(int *T, int imin, int imax){

    int v, i, j, temp;

    v = T[imax];
    i = imin;
    j = imax - 1;

    while(i <= j){
        while(i < imax && T[i] <= v){
            i++;
        }

        while(j >= imin && T[j] >= v){
            j--;
        }

        if(i < j){
            temp = T[i];
            T[i] = T[j];
            T[j] = temp;
        }
    }

    T[imax] = T[i];
    T[i] = v;

    return i;
}

void ClassifRapid(int *T, int imin, int imax){

    int i;

    if(imin < imax){

        i = Particionamento(T, imin, imax);
        ClassifRapid(T, imin, i - 1);
        ClassifRapid(T, i + 1, imax);

    }
}

void QuickSort(int *T, int n){

    ClassifRapid(T, 0, n - 1);
}