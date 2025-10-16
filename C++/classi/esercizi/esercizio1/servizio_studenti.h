#ifndef SERVIZIO_STUDENTI_H
#define SERVIZIO_STUDENTI_H

#include <string>
#include "studente.h"
using namespace std;

class ServizioStudenti {
    private:
        Studente studenti[10];
    public:
        ServizioStudenti(Studente studenti[]);
        ~ServizioStudenti();

        void stampaStudenti() const;
        Studente ricercaStudentePerNome(string nome) const;
        void ordinaStudentiPerMedia();
};

#endif