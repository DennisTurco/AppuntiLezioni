#ifndef RETTA_H
#define RETTA_H

#include "Polinomio.h"

class Retta: public Polinomio {
public:
	// Crea una retta ax+b
	Retta(double a, double b): Polinomio(std::vector<double>{b,a}) {} //richiamo costruttore?
};

#endif // RETTA_H