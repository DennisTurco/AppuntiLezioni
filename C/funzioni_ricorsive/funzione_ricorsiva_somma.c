#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 3 2 6 4

int somma(int val[], int dim) {
    // caso base
    if (dim <= 0) return 0;

    // passo induttivo
    return val[dim-1] + somma(val, dim-1);
}

/*
funzione 1 -> val = [3, 2, 6, 4], dim = 4 -> return 4 + somma(val, 3)
    funzione 2 -> val = [3, 2, 6, 4], dim = 3 -> return 6 + somma(val, 2)
        funzione 3 -> val = [3, 2, 6, 4], dim = 2 -> return 2 + somma(val, 1)
            funzione 4 -> val = [3, 2, 6, 4], dim = 1 -> return 3 + somma(val, 0)
                funzione 5 -> val = [3, 2, 6, 4], dim = 0 -> return 0
                Termina la funzione 5 restituendo 3
            Termina la funzione 4 restituendo 5
        Termina la funzione 3 restituendo 11
    Termina la funzione 2 restituendo 15
Termina la funzione 1 restituendo 15
*/

int main () {
    const int dim = 5;

    int val[dim];
    srand(time(NULL));

    for (int i = 0; i < dim; i++) {
        val[i] = rand() % 10;
    }

    for (int i = 0; i < dim; i++) {
        printf("%d ", val[i]);
    }

    printf("\nsomma = %d", somma(val, dim));

    return 0;
}