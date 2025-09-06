#include <stdio.h>

void stampa(int a[], int dim) {
    for (int i = 0; i < dim ; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int const dim = 5;
    int valori[] = {1, 5, 2, 7, 3}; // --> [1, 2, 5, 3, 7]

    // stampa
    stampa(valori, dim);

    // scambi
    for (int i = 0; i < dim-1; i++) {
        if (valori[i] > valori[i+1]) {
            int temp = valori[i];
            valori[i] = valori[i+1];
            valori[i+1] = temp;
        }
    }

    // stampa
    stampa(valori, dim);
    
    return 0;
}