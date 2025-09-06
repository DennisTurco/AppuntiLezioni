#ifndef FUNZIONE_H
#define FUNZIONE_H

#include <iostream>
#include <string>

class Funzione{
public:

    virtual ~Funzione() {}

    //Calcola il valore della funzione f(x) per un dato x.
    virtual double val(double x) const = 0;

    // Restituisce una rappresentazione testuale della funzione.
	virtual std::string str() const = 0;

	//Converte la funzione in stringa.
	//virtual operator std::string() const = 0;
};

std::ostream& operator<<(std::ostream& os, const Funzione& f) {
	return os << f.str();
}

#endif // FUNZIONE_H