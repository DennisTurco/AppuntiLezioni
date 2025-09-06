#ifndef LOGARITMO_H
#define LOGARITMO_H

#include <cmath>
#include <iostream>
#include <string>
#include "Funzione.h"

using namespace std;

class Logaritmo : public Funzione{
public:
    // Crea logaritmo naturale ln(x).
	Logaritmo() {}

	// Crea logaritmo in base b log_b(x).
	Logaritmo(int b){
	    base = b;
	}

	double val(double x) const override {
		if (base<0) return log(x);
		else if (base==2) return log2(x);
		else if (base==10) return log10(x);
		else return log(x)/log(base);
	}

	string str() const override {
		if (base<=0) return "ln(x)";
		if (base==2) return "log2(x)";
		if (base==10) return "log10(x)";
		// else
		return "log"+to_string(base)+"(x)";
	}

private:
    int base=-1;

};

#endif // LOGARITMO_H