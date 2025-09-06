#ifndef PARABOLA_H
#define PARABOLA_H

#include "Polinomio.h"

class Parabola : public Polinomio {
public:
    // Crea una parabola ax^2+bx+c.
    Parabola(double a, double b, double c): Polinomio(std::vector{c, b, a}) {} //richiamo costruttore?
};
#endif // PARABOLA_H