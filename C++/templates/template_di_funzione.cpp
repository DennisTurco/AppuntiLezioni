#include <iostream>
using namespace std;

/*
int somma(int a, int b) {
    return a + b;
}

char somma(char a, char b) {
    return a + b;
}
*/

template <typename T>
T somma (T a, T b) {
    return a + b;
}

template <typename T, typename U>
void stampa(T a, U b) {
    cout << a << " e " << b;
}

int main () {
    cout << somma('Z', 'c') << endl;
    cout << somma(6, 4) << endl;
    cout << somma(6.3, 4.2) << endl;

    cout << "-----------------\n";

    stampa(5, "ciao");
    return 0;
}