#include <iostream>
#include <time.h>
using namespace std;

int main () {

    srand(time(NULL));

    int dim = 20;
    int vet[dim];

    // popolamento array
    for (int i = 0; i < dim; i++) {
        vet[i] = rand() % 10;
    }

    // stampa array
    for (int i = 0; i < dim; i++) {
        cout << vet[i] << " ";
    }
    cout << endl;

    // selection sort
    for (int i = 0; i < dim; i++) {
        int min = i; // indice del valore minimo

        // questo ciclo ci serve per ottenere l'indice del valore minimo
        for (int j = i + 1; j < dim; j++) {
            if (vet[j] < vet[min]) {
                min = j;
            }
        }

        // a questo punto abbiamo l'indice del valore minimo e la posizione i-esima (corrente)
        // quindi possiamo scambiare i due valori (vet[i] e vet[min])
        int temp = vet[i];
        vet[i] = vet[min];
        vet[min] = temp;
    }

    // stampa array ordinato
    for (int i = 0; i < dim; i++) {
        cout << vet[i] << " ";
    }
}