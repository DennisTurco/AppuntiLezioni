#include <iostream>

using namespace std;

int main () {
    // ################ array statici ################
    // allocato nella memoria nello stack
    int valori[5];      // dimensione costante

    // ################ array semi-dinamici ################
    // allocato nella memoria nello stack
    int dim;
    cout << "Inserisci la grandezza: ";
    cin >> dim;
    int valori2[dim];   // dimensione variabile

    // ################ array dinamici ################
    // allocato nella memoria dello heap
    int* valori3 = new int[10]; // allocazione
    // ...
    delete[] valori3;   // deallocazione
}