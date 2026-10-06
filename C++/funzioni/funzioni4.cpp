#include <iostream>
using namespace std;

int differenza(int, int); // prototipo

int main() {
    int a = 12;
    int b = 5;
    int risultato = differenza(a, b);
}

int differenza(int x, int y) {
    // x = 12, y = 5
    x = 100;
    y = 200;
    // x = 100, y = 200
    // a = 12, b = 5 --> valgono ancora 12 e 5 perchè è un passaggio parametri per valore, quindi x e y sono una copia
    return y - x; // --> 100
}
