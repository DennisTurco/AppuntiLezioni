#include <iostream>
using namespace std;




/*
// PROBLEMA di questa versione: staimo duplicando del codice
// questa cosa in programmazione non si fa per tanti motivi tra cui:
// poco leggibile, poco manutenibile, meno ordinato
int main () {
    int numeri[] = {3, 2, 1, 2, 4, 6, 3};

    // stampa
    for (int i = 0; i < 7; i++) {
        cout << numeri[i] << " ";
    }

    // modifiche a caso
    numeri[0] = 10;
    numeri[3] = 20;
    numeri[5] = 30;
    cout << endl;

    // stampa
    for (int i = 0; i < 7; i++) {
        cout << numeri[i] << " ";
    }

    // altre modifiche a caso
    numeri[1] = 1;
    numeri[4] = 0;
    numeri[6] = 8;
    cout << endl;

    // stampa
    for (int i = 0; i < 7; i++) {
        cout << numeri[i] << " ";
    }
}
*/

// ################# SOLUZIONE

// void perche' non ritorna (restituisce) nulla al chiamante
// stampa_vettore e' il nome che gli dai
// (int valori[], int dimensione) sono i parametri della funzione -> ciò di cui necessita per operare
void stampa_vettore(int valori[], int dimensione) {
    for (int i = 0; i < dimensione; i++) {
        cout << valori[i] << " ";
    }
}

int main () {
    int numeri[7] = {3, 2, 1, 2, 4, 6, 3};
    
    // stampa
    stampa_vettore(numeri, 7); // chiamata di funzione

    // modifiche a caso
    numeri[0] = 10;
    numeri[3] = 20;
    numeri[5] = 30;
    cout << endl;

    // stampa
    stampa_vettore(numeri, 7);

    // altre modifiche a caso
    numeri[1] = 1;
    numeri[4] = 0;
    numeri[6] = 8;
    cout << endl;

    // stampa
    stampa_vettore(numeri, 7);
}