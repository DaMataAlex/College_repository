#include <stdio.h>

void SelectionSort(int *T, int n){

    int k, i, imax, temp;

    for (k = n - 1; k > 0; k--){
        imax = 0;

        for (i = 1; i <= k; i++) {
            if (T[imax] < T[i]) {
                imax = i;
            }
        }

        temp   = T[k];
        T[k]   = T[imax];
        T[imax] = temp;
    }
}