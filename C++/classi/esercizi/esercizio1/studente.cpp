#include "studente.h"
#include <iostream>
using namespace std;

Studente::Studente(string nome, string cognome, int eta, double voti[]) {
    this->nome = nome;
    this->cognome = cognome;
    this->eta = eta;
    for (int i = 0; i < 3; i++) {
        this->voti[i] = voti[i];
    }
}

Studente::~Studente() { }

double Studente::mediaVoti() const {
    double somma = 0;
    for (int i = 0; i < 3; i++) {
        somma += voti[i];
    }
    return somma / 3;
}

double Studente::mediaVotiRicorsiva(int i) const {
    int numVoti = 3;
    if(i == numVoti) {
        return 0;
    }
    return (voti[i] + mediaRicorsiva(i+1)*(numVoti-i-1))/(numVoti-i);
}

void Studente::stampa() const {
    cout << nome << " " << cognome << ", eta: " << eta << ", media: " << mediaVoti() << endl;
}

// getter
string Studente::getNome() const {
    return nome;
}
string Studente::getCognome() const {
    return cognome;
}
int Studente::getEta() const {
    return eta;
}
double* Studente::getVoti() const {
    return voti;
}

bool Studente::operator>(Studente& s) const {
    return this->mediaVoti() > s.mediaVoti();
}