#include <iostream>
#include <string>

using namespace std;

class Paragrafo {
private:
    string p_titolo;
    string p_testo;

public:
    Paragrafo(const string& titolo, const string& testo) : p_titolo(titolo), p_testo(testo) { }

    // restituisce il titolo del paragrafo
    string titolo() const {
        return p_titolo;
    }

    // restituisce il testo del paragrafo
    string testo() const {
        return p_testo;
    }
};
