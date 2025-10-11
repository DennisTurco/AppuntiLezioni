#include <iostream>
#include <cmath>
using namespace std;

// classe astratta: classe base, non esiste da sola, ma e' dipendente

// una classe per essere astratta deve sempre avere i metodi virtual
class Forma {
    public:
        // metodo virtuale puro -> rende la classe astratta
        virtual double area() const = 0;

        // metodo virtuale normale
        virtual void disegna() const {
            cout << "Disegna una forma geometrica\n";
        }

        // distruttore virtuale (obbligatorio nelle classi virtuali)
        virtual ~Forma() {} //per il carattere ~: tenere premuto ALT + 1 + 2 + 6 (del tastierino numerico)
};


// classe concreta: classe completa, e' indipendente, puo' essere istanziata.
//                  In questo caso essendo legata alla classe astratta, implementa anche tutti i suoi metodi

class Cerchio : public Forma { // cerchio eredita da forma tutto cio' che e' public
    private:
        double raggio;
    public:
        Cerchio(double raggio) : raggio(raggio) {} // costruttore con lista di inizializzazione

        double area() const override { // implementazione obbligatoria
            return M_PI * raggio * raggio;
        }

        // void disegna() const override {
        //     cout << "Disegna cerchio di raggio: " << raggio << endl;
        // }
};


int main() {

    Cerchio c(5);
    c.disegna();
    cout << "Area: " << c.area() << endl;

    return 0;
}
