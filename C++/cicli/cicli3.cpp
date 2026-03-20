/*
    Programma che chiede all'utente n voti (con n definito da utente). Il programma calcola
    la media dei voti, stampa il maggiore e il minore.
*/

#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int voti;
    cout << "Quanti voti vuoi mettere? ";
    cin >> voti;

    int voto;
    float media = 0;
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < voti; i++) {
        cout << "voto: ";
        cin >> voto;
        media = ((media * i) + voto) / (i + 1);

        if (voto > max)
            max = voto;
        if (voto < min)
            min = voto;
    }
    cout << "la media e': " << media << endl;
    cout << "Il massimo e': " << max << endl;
    cout << "Il minimo e': " << min;
}