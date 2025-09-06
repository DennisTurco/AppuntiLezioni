/*
Dato un array di n elementi trovare il valore che si ripete piu' volte
*/


#include <stdio.h>

int main () {
    int const dim = 5;

    int punteggi[] = {1, 5, 3, 5, 5}; 
    int occorrenze[dim]; // --> [1, 3, 1, 3, 3]

    for (int i = 0; i < dim; i++) {
        occorrenze[i] = 0;
    }

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (punteggi[i] == punteggi[j]) {
                occorrenze[i]++;
            }
        }
    }

    // stampa occorrenze
    for (int i = 0; i< dim; i++) {
        printf("%d ", occorrenze[i]);
    }

    return 0;
}