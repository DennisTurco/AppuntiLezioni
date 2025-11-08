#include <iostream>
#include <set>
using namespace std;

// i set sono delle collezioni di valori unici, ordinati per valore

int main () {
    set<int> valori;

    // inserimento
    valori.insert(5);
    valori.insert(2);
    valori.insert(7);
    valori.insert(5);
    valori.insert(5);

    // stampo iterando il contenuto del set
    for (int elem : valori) {
        cout << elem << " ";
    }

    cout << endl;

    // ricerca valore 3 nel set
    if (valori.count(3)) {
        cout << "Trovato!";
    } else {
        cout << "Valore non presente";
    }

    cout << endl;

    // cancellazione
    valori.erase(5);
    for (int elem : valori) {
        cout << elem << " ";
    }

    return 0;
}