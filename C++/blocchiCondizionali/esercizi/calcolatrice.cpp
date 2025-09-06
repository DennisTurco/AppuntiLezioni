#include <iostream>
using namespace std;

// l'utente inserisce 2 numeri
// seleziona l'operazio che vuole eseguire (+, -, *, /)
// restuiamo all'utente il risultato

int main () {
    float valore1;
    float valore2;
    float somma;
    float sottrazione;
    float prodotto;
    float divisione;
    int scelta;

    cout << "Inserisci valore 1: ";
    cin >> valore1;
    cout << "Inserisci valore 2: ";
    cin >> valore2;

    cout << "Scegli l'operazione: \n1) somma; \n2) sottrazione; \n3) prodotto; \n4) divisione; \nScelta: ";
    cin >> scelta;
    
    // VERSIONE IF/ELSE
    if (scelta == 1) {
        somma = valore1 + valore2;
        cout << "Somma = " << somma;
    }
    else if (scelta == 2) {
        sottrazione = valore1 - valore2;
        cout << "Sottrazione = " << sottrazione;
    }
    else if (scelta == 3) {
        prodotto = valore1 * valore2;
        cout << "Prodotto = " << prodotto;
    }
    else if (scelta == 4) {
        divisione = valore1 / valore2;
        cout << "Divisione = " << divisione;
    }
    else {
        cout << "Errore!!!\n";
    }


    // VERSIONE SWITCH
    /*switch (scelta) {
        // se scelta == 1
        case 1:  
            somma = valore1 + valore2;
            cout << "Somma = " << somma;
            break;

        // se scelta == 2
        case 2: 
            sottrazione = valore1 - valore2;
            cout << "Sottrazione = " << sottrazione;
            break;

        // se scelta == 3
        case 3: 
            prodotto = valore1 * valore2;
            cout << "Prodotto = " << prodotto;
            break;

        // se scelta == 4
        case 4: 
            divisione = valore1 / valore2;
            cout << "Divisione = " << divisione;
            break;

        // altrimenti
        default: 
            cout << "Errore!!!\n";
            break;
    }*/

    


    cout << endl << endl;
}



/* Output:

    Inserisci valore 1: 4
    Inserisci Operazione: +
    Inserisci valore 2: 5

    Risultato = 9



    VErsione senza scritte:
    4
    +
    5
    
    = 9
*/