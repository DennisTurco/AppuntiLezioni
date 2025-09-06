#include <iostream>
using namespace std;

int main () {
    for (int i = 0; i < 10; i++) { // i++ significa i = i + 1
        cout << i << " ";
    }

    cout << endl;

    for (int i = 0; i < 10; i+=2) { // i+=n significa i = i + n, con n naturale
        cout << i << " ";
    }

    cout << endl;

    for (int i = 1; i < 10; i*=2) { // i*=n significa i = i * n, con n naturale
        cout << i << " ";
    }

    cout << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Ciao ";
    }

    cout << endl;

    for (int i = 0; i <= 20; i++) {
        cout << i/2 << " ";
    }

    cout << endl;

    for (int i = 0; i <= 20; i++) {
        cout << i%2 << " ";
    }

    int somma = 0;
    for (int i = 0; i < 3; i++) {
        somma = somma + i; // somma += i;
    }
}

/* i++ equivale a i = i + 1
    i = 0;
    i++ -> i = 0 + 1 -> i = 1
    i++ -> i = 1 + 1 -> i = 2
    i++ -> i = 2 + 1 -> i = 3
    i++ -> i = 3 + 1 -> i = 4
    ...
*/