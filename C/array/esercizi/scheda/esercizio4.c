#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// numeri      = [2, 3, 2, 4, 2]
// occorrenze  = [3, 1, 3, 1, 3]

int main () {
    srand(time(NULL));
    int numeri[15];
    int occorrenze[15];

    // popolamento numeri nel vettore
    for (int i = 0; i < 15; i++) {
        numeri[i] = rand() % 10 + 1;
        printf("%d ", numeri[i]);
    }

    // coostruzione del vettore occorrenze
    for (int i = 0; i < 15; i++) { // per spostarti di posizione in posizione
        int n_occ = 0;
        for (int j = 0; j < 15; j++) { // per contare quante occorrenze per quella posizione
            if (numeri[i] == numeri[j]) {
                n_occ++;
            }
        }
        occorrenze[i] = n_occ;
    }

    // ricerca max in occorrenze
    int pos_max = 0;
    for (int i = 0; i < 15; i++) {
        if (occorrenze[pos_max] < occorrenze[i]) {
            pos_max = i;
        }
    }

    // stampa finale
    printf("\nIl valore con numero di occorrenze maggiore e': %d", numeri[pos_max]);
    printf("\nE si ripete %d volte", occorrenze[pos_max]);
}


// 3 10 2 8 7 5 7 5 3 5 4 8 7 6 2 
// Il valore con numero di occorrenze maggiore e': 7
// E si ripete 3 volte