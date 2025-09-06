#ifndef  ESPONENZIALE_H
#define ESPONENZIALE_H

#include "Funzione.h"
#include <iostream>
#include <cmath>

using namespace std;

class Esponenziale : public Funzione{
public:
    // Crea la funzione e^x.
	Esponenziale() {}

	double val(double x) const override {
		return exp(x);
	}

	string str() const override {
		return "e^x";
	}
};

#endif // ESPONENZIALE_H