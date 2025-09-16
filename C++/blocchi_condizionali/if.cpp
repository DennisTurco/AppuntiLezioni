#include <iostream>
using namespace std;

int main () {
    int valore;

    cout << "Dammi un valore: ";
    cin >> valore;

    // nelle parentesi dell'if mettiamo la condizione che puo' essere vera o falsa
    // se la condizione e' vera entriamo nel blocco dell'if, altrimenti lo ignoriamo
    // in un blocco if-else entrera' solo in un caso non di piu' e non di meno
    if (valore > 10) { 
        cout << "entrato nell'if" << endl;
    }
    else if (valore == 10) { 
        cout << "entrato nell'else if" << endl;
    }
    else if (valore == 20) { 
        cout << "entrato nell'else if2" << endl;
    }
    else { 
        cout << "entrato nell'else" << endl;
    }

    cout << "Programma Terminato!";
}