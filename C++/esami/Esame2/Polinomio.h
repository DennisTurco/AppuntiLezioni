#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Funzione.h"

class Polinomio : public Funzione {  //derivata da Funzione
public:
    // costruttore che crea polinomio nullo
    Polinomio() {}

    // Crea un polinomio di grado n specificando gli n+1 coefficienti c0, c1, cN.
	Polinomio(const std::vector<double>& cc){
	    coeff = cc;
	}

	// Leggi gli n+1 coefficienti da file.
	Polinomio(const std::string& filename) {
		std::ifstream fin{filename};
		double c;
		while (fin>>c) coeff.push_back(c);
		fin.close();
	}

    //Restituisce il grado del polinomio.
	int grado() const{
	    return coeff.size()-1;
	}

	// Restituisce i coefficienti del polinomio.
	std::vector<double> coefficienti() const{
	    return coeff;
	}

	double val(double x) const override {
		double somma= 0;
		double xi= 1;
		for (decltype(coeff.size()) i= 0; i<coeff.size(); ++i) {
			somma += coeff[i]*xi;
			xi *= x;
		}
		return somma;
	}

	std::string str() const override {
		std::ostringstream ss;
		int grado = coeff.size()-1;
		for (int i=grado; i>=0; --i) {
			if (coeff[i]!=0) {
				if (coeff[i]>0) {
					ss<<(i==grado?"":" + ");
					if (coeff[i]!=1 || i==0) ss<<coeff[i];
				}
				else ss<<" - "<<-coeff[i];
				if (i>1) ss<<"x^"<<i;
				else if (i==1) ss<<"x";
			}
		}
		return ss.str();
	}


protected:  //vanno messi protected così saranno visibili nelle classi derivate
    std::vector<double> coeff; // coefficienti c0, c1, c2, ..., cN
};
#endif // POLINOMIO_H