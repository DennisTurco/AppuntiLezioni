/*
    Programma che stampa un triangolo rettangolo usando un doppio ciclo for:
    *
    ***
    *****
*/

#include <iostream>
using namespace std;

int main() {
    int row = 3;
    int col = 5;

    for (int i = 0; i < row; i++) {        // per le righe
        for (int j = 0; j < col; j++) {    // per le colonne
            if (j >= 2 * i + 1)
                break;
            cout << "*";
        }
        cout << "\n";
    }
}