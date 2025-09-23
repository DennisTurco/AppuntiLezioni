#include <iostream>
using namespace std;

class Frazione {
private:
    // attributi
    int numeratore;
    int denominatore;

public:
    // metodi
    // costruttore della classe
    Frazione(int numeratore, int denominatore) {
        if (denominatore == 0) {
            cout << "Errore! il denominatore non puo' essere 0";
            exit(-1);
        }
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

    // getter
    int get_numeratore() {
        return numeratore;
    }
    int get_denominatore() {
        return denominatore;
    }

    // setter
    void set_numeratore(int numeratore) {
        this->numeratore = numeratore;
    }
    void set_denominatore(int denominatore) {
        if (denominatore == 0) {
            cout << "Errore! il denominatore non puo' essere 0";
            exit(-1);
        }
        this->denominatore = denominatore;
    }
};

int main () {
    Frazione fra(2, 3);
    fra.stampa_frazione();
    cout << fra.get_numeratore() << endl;

    fra.set_denominatore(2);
    cout << fra.to_razionale();
    return 0;
}