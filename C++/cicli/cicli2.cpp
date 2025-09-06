#include <iostream>
using namespace std;

// è indifferente usare un for o un while per il ciclo.
// generalmente è preferibile usare il for quando so esattamente il numero di iterazioni da fare
// il while quando non so quante farne

int main () {

    for (int i = 0; i <= 20; i++) {
        if (i % 2 == 0) { // modulo restuisce il resto della divisione (in questo caso per 2)
            cout << i << " ";
        }
    }

    cout << endl;

    int i = 0;
    while (i <= 20) {
        if (i % 2 == 0) { 
            cout << i << " ";
        }
        i++;
    }

    int valore = 1;
    while (valore > 0) {
        cin >> valore;
    }
}