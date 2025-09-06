/*
Programmazione ad oggetti

Esercitazione su metodi virtuali e classi astratte


1) Creare una classe astratta (pura) "Funzione" e le sottoclassi "Polinomio", "Retta", "Parabola", "Esponenziale", "Logaritmo", le cui interfacce pubblche sono indicate qui di seguito.

Classe astratta Funzione (solo metodi virtuali puri):

	// Calcola il valore della funzione f(x) per un dato x.
	virtual double val(double x) const;

	// Restituisce una rappresentazione testuale della funzione.
	virtual std::string str() const;


Classe Polinomio:

	// Crea polinomio nullo.
	Polinomio();

	// Crea un polinomio di grado n specificando gli n+1 coefficienti c0, c1, cN.
	Polinomio(const std::vector<double>& cc);

	// Restituisce il grado del polinomio.
	int grado() const;

	// Restituisce i coefficienti del polinomio.
	std::vector<double> coefficienti() const;


Classe Retta:

	// Crea una retta ax+b.
	Retta(double a, double b);


Classe Parabola:

	// Crea una parabola ax^2+bx+c.
	Parabola(double a, double b, double c);


Classe Esponenziale:

	// Crea la funzione e^x.
	Esponenziale();


Classe Logaritmo:

	// Crea logaritmo naturale ln(x).
	Logaritmo();

	// Crea logaritmo in base b log_b(x).
	Logaritmo(int b);


Con queste classi provare il seguente codice:

	vector<Funzione*> funzioni;
	funzioni.push_back(new Polinomio(vector<double>{1,2,1}));
	funzioni.push_back(new Retta(1,5));
	funzioni.push_back(new Parabola(2,4,1));
	funzioni.push_back(new Esponenziale());
	funzioni.push_back(new Logaritmo());
	funzioni.push_back(new Logaritmo(2));

	double x= 2;
	cout << "x= " << x << endl << endl;
	for (auto fp: funzioni) cout << fp->str() << " -> " << fp->val(x) << endl << endl;

	for (auto fp: funzioni) delete fp;
	funzioni.clear();

	Polinomio p1(vector<double>{1,2,1});
	Esponenziale e1;
	cout << endl << "e^2x + 2e^x+ 1 -> " << p1.val(e1.val(x)) << endl << endl;




2) Sovraccaricare l'operatore << in modo da scrivere un oggetto Funzione su ostream. Modificare il programma di test sostituendo il primo ciclo 'for' con.

	for (auto fp: funzioni) cout << fp << " -> " << fp->val(x) << endl << endl;




3) In Polinomio aggiungere un costruttore che legge i coefficienti da file:

	// Leggi gli n+1 coefficienti da file.
	Polinomio(const std::string& filename)

Provare il nuovo costruttore leggendo da un file "coefficienti.txt" i coefficineti "5 4 3 2 1":

	Polinomio p2("coefficienti.txt");
	cout << p2.str() << endl;
*/


#include <iostream>
#include <vector>

#include "Funzione.h"
#include "Polinomio.h"
#include "Retta.h"
#include "Parabola.h"
#include "Esponenziale.h"
#include "Logaritmo.h"

using namespace std;

int main()
{
    vector<Funzione*> funzioni;
	funzioni.push_back(new Polinomio(vector<double>{1,2,1}));  //push_back inserisce un nuovo elemento alla fine (espande il vettore se necessario)
	funzioni.push_back(new Retta(1,5));
	funzioni.push_back(new Parabola(2,4,1));
	funzioni.push_back(new Esponenziale());
	funzioni.push_back(new Logaritmo());
	funzioni.push_back(new Logaritmo(2));

	double x = 2;
	cout << "x= " << x << endl << endl;
	//for (const auto fp: funzioni) cout << fp->str() << " -> " << fp->val(x) << endl << endl;
	for (const auto fp: funzioni) cout << *fp << " -> " << fp->val(x) << endl << endl;

	for (auto fp: funzioni) delete fp;
	funzioni.clear();

	Polinomio p1(vector<double>{1,2,1});
	Esponenziale e1;
	cout << endl << "e^2x + 2e^x+ 1 -> " << p1.val(e1.val(x)) << endl << endl;

	Polinomio p2("coefficienti.txt");
	cout << p2.str() << endl;


    return 0;
}