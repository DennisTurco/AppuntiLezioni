#include <iostream>
#include <time.h>
using namespace std;

int main () {
    srand(time(NULL));

    // dichiarazione array
    int valori[5];

    // popolamento array casualmente
    for (int i = 0; i < 5; i++) {
        int v = rand() % 10;
        valori[i] = v;
    }

    // stampa array
    cout << "Stampiamo l'array: \n";
    for (int i = 0; i < 5; i++) {
        cout << valori[i] << " ";
    }

    // modifico la posizione 3 con il valore 10
    valori[3] = 10;
    // modifico la posizione 4 con il valore della posizione 1 + il valore della posizione 2
    valori[4] = valori[1] + valori[2];

    // stampa array
    cout << "\n\nStampiamo l'array: \n";
    for (int i = 0; i < 5; i++) {
        cout << valori[i] << " ";
    }

    return 0;
}