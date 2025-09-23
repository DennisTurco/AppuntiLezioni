#include <iostream>
#include <time.h>
using namespace std;

class Frazione {
public:
    int numeratore;
    int denominatore;

    // costruttore della classe
    Frazione(int numeratore, int denominatore) {
        this->numeratore = numeratore;
        this->denominatore = denominatore;
    }

    Frazione() {
        this->numeratore = 0;
        this->denominatore = 1;
    }

    void stampa_frazione(){
        cout << numeratore << " / " << denominatore << endl;
    }

    float to_razionale() {
        return (float) numeratore / denominatore;
    }
};

int main () {
    // ------------------- PARTE 1
    Frazione frazione;
    frazione.stampa_frazione();
    cout << frazione.to_razionale() << endl << endl;

    // ------------------- PARTE 2
    srand(time(NULL));
    int dim = 5;
    Frazione* frazioni = new Frazione[dim];

    for (int i = 0; i < dim; i++) {
        int num = rand() % 10;
        int den = rand() % 9 + 1;
        frazioni[i] = Frazione(num, den);
        cout << frazioni[i].to_razionale() << endl;
    }

    delete[] frazioni;
    return 0;
}