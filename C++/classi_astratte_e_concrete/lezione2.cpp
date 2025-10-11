#include <iostream>
#include <cmath>
using namespace std;

class Forma {
    public:
        virtual double area() const = 0;

        virtual void disegna() const {
            cout << "Disegna una forma geometrica\n";
        }

        virtual ~Forma() {
            cout << "Disruttore chiamato\n\n";
        }
};


class Cerchio : public Forma {
    private:
        double raggio;
    public:
        Cerchio(double raggio) : raggio(raggio) {}

        double area() const override {
            return M_PI * raggio * raggio;
        }

        void disegna() const override {
            cout << "Disegna cerchio di raggio: " << raggio << endl;
        }
};


class Rettangolo : public Forma {
    private:
        double base;
        double altezza;
    public:
        Rettangolo(double base, double altezza) : base(base), altezza(altezza) {}

        double area() const override {
            return base * altezza;
        }

        void disegna() const override {
            cout << "Disegna rettangolo di base: " << base << " e di altezza: " << altezza << endl;
        }
};


int main() {

    Forma* forme[] = {new Cerchio(2.3), new Rettangolo(3, 4.5)};

    for (auto f : forme) {
        f->disegna();
        cout << "Area: " << f->area() << endl;
        delete f;
    }

    return 0;
}
