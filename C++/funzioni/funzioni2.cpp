#include <iostream>
using namespace std;

// void perche' non ritorna (restituisce) nulla al chiamante
// stampa_vettore e' il nome che gli dai
// (int valori[], int dimensione) sono i parametri della funzione -> ciò di cui necessita per operare
void stampa_vettore(int valori[], int dimensione) {
    for (int i = 0; i < dimensione; i++) {
        cout << valori[i] << " ";
    }
}

void incrementa_pari_o_dispari(int valori[], int dimensione, bool pari) {
    int resto;
    if (pari == true) {
        resto = 0;
    } else {
        resto = 1;
    }

    for (int i = 0; i < dimensione; i++) {
        if (valori[i] % 2 == resto) {
            valori[i]++; // uguale a valori[i] += 1; oppure uguale a valori[i] = valori[i] + 1;
        }
    }
}

int somma_totale(int valori[], int dimensione) {
    int somma = 0;
    for (int i = 0; i < dimensione; i++) {
        somma += valori[i];
    }

    return somma;
}

int main () {
    int numeri[7] = {3, 2, 1, 2, 4, 6, 3};
    
    // stampa
    stampa_vettore(numeri, 7); // chiamata di funzione
    cout << endl;

    // modifico tutti i valori pari con il successivo (se e' 2, metto 3)
    incrementa_pari_o_dispari(numeri, 7, true);

    // stampa
    stampa_vettore(numeri, 7);
    cout << endl;

    // modifico tutti i valori dispari con il successivo (se e' 3, metto 4)
    incrementa_pari_o_dispari(numeri, 7, false);

    // stampa
    stampa_vettore(numeri, 7);
    cout << endl;

    int res = somma_totale(numeri, 7);
    cout << "La somma totale e' " << res << endl;
}