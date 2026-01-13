#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Capitolo {
private:
    string c_titolo;
    vector<Paragrafo> c_paragrafi;

public:
    Capitolo(const string& titolo) : c_titolo(titolo) { }

    // aggiunge un nuovo paragrafo
    void add(const Paragrafo& par) {
        c_paragrafi.push_back(par);
    }

    // restituisce il titolo del capitolo
    string titolo() const {
        return c_titolo;
    }

    // restituisce la lista dei paragrafi
    const vector<Paragrafo>& paragrafi() const {
        return c_paragrafi;
    }
};
