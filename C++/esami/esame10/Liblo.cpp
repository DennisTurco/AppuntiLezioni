#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Libro {
private:
    string l_titolo;
    vector<Capitolo> l_capitoli;
public:
    Libro(const string& titolo) : l_titolo(titolo) { }

    // aggiunge un nuovo capitolo
    void add(const Capitolo& cap) {
        l_capitoli.push_back(cap);
    }

    // restituisce il titolo del libro
    string titolo() const {
        return l_titolo;
    }

    // restituisce la lista dei capitoli
    const vector<Capitolo>& capitoli() const {
        return l_capitoli;
    }

    // scrive su std::ostream il contenuto del libro
    void print(ostream& out) const {
        out << l_titolo << endl << endl;

        int c = 1;
        for (const auto& cap : l_capitoli) {
            out << c << ". " << c.titolo() << endl << endl;

            int p = 1;
            for (const auto& par : cap.paragrafi()) {
                out << c << "." << p << ". " << p.titolo() << endl;
                out << p.testo() << endl;
                p++;
            }
            c++;
        }
    }
};

ostream& operator<<(ostream& os, const Libro& libro) {
    libro.print(os);
    return os;
}
