/*
    1. L'utente inserisce 5 valori interi (tramite terminale)
    2. stampiamo il set di valori inseriti (tramite una funzione)
    3. si trova il massimo (tramite funzione)
    4. si calcola la media (tramite funzione)
    5. si stampa il massimo e la media (nel main)
*/

#include <iostream>
using namespace std;

void stampa(int valori[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << valori[i] << " ";
    }
}

int max(int valori[], int dim) {
    // il massimo di un insieme appartiene all'insieme
    int massimo = valori[0];
    
    for (int i = 0; i < dim; i++) {
        if (valori[i] > massimo) {
            massimo = valori[i]; // aggiorno il nuovo massimo
        }
    }

    return massimo;
}

int main () {
    int valori[5];
    
    // 1. inserimento del valori
    cout << "inserisci 5 valori: ";
    for (int i = 0; i < 5; i++) {
        cin >> valori[i];
    }

    // 2. stampa dei valori
    stampa(valori, 5);              // chiamata di funzione

    // 3. trovare il massimo
    int massimo = max(valori, 5);   // chiamata di funzione

    cout << "\nmassimo = " << massimo;

}