#include "servizio_studenti.h"
#include <iostream>
using namespace std;

ServizioStudenti::ServizioStudenti(Studente studentiArray[]) {
    for (int i = 0; i < 3; i++) {
        studenti[i] = studentiArray[i];
    }
}

ServizioStudenti::~ServizioStudenti() { }

void ServizioStudenti::stampaStudenti() const {
    for (int i = 0; i < 3; i++) {
        studenti[i].stampa();
        cout << "------------------" << endl;
    }
}

Studente ServizioStudenti::ricercaStudentePerNome(string nome) const {
    for (int i = 0; i < 10; i++) {
        if (studenti[i].getNome() == nome) {
            return studenti[i];
        }
    }
    cout << "Studente non trovato! Restituisco il primo della lista." << endl;
    return studenti[0];
}

// ordinamento bubble sort
void ServizioStudenti::ordinaStudentiPerMedia() {
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (studenti[j] > studenti[i]) {
                Studente temp = studenti[i];
                studenti[i] = studenti[j];
                studenti[j] = temp;
            }
        }
    }
}