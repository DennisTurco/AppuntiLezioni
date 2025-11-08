#include <iostream>
#include <map>
using namespace std;

// map = collezioni di valori costuiti da coppie -> chiave - valore, dove la chiave e' sempre unica, ordinano in base alla chiave

int main () {
    map<string, int> persone;

    // inserimento
    persone["Franco"] = 2001;
    persone["Anna"] = 2001;
    persone["Franco"] = 2004;
    persone["Maria"] = 1999;

    // stampa con iterazione
    for (auto [chiave, valore] : persone) {
        cout << "Chiave: " << chiave << ", Valore: " << valore << endl;
    }

    // ricerca
    if (persone.count("Gianfranco")) {
        cout << "Trovato!";
    } else {
        cout << "Valore non presente";
    }

    cout << endl;

    // cancellazione
    persone.erase("Maria");
    for (auto [chiave, valore] : persone) {
        cout << "Chiave: " << chiave << ", Valore: " << valore << endl;
    }

    return 0;
}