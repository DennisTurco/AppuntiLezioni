#include <iostream>
using namespace std;

int func(int x, int y) {
    return x + y;
}

// funzioni labda: funzioni anonime -> vengono dichiarate e utilizzate direttamente nel punto di utilizzo
// [cattura] (parametri) -> tipo_di_ritorno { corpo; };

int main() {
    int a = 5;
    int b = 4;

    // con funzione classica
    auto risultato = func(a, b);
    cout << risultato << endl;

    // con lambda
    auto somma = [a, b]() -> int { return a + b; };
    cout << "Somma: " << somma() << endl;

    auto moltiplicazione = [](int x, int y) -> int { return x * y; };
    cout << "Moltiplicazione: " << moltiplicazione(4, 6) << endl;

    return 0;
}