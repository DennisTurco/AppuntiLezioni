#ifndef STUDENTE_H
#define STUDENTE_H

#include <string>
using namespace std;

class Studente {
    private:
        string nome;
        string cognome;
        int eta;
        double voti[3];

    public:
        Studente(string nome, string cognome, int eta, double voti[]);
        ~Studente();

        double mediaVoti() const;
        double mediaVotiRicorsiva() const;

        void stampa() const;

        // getter
        string getNome() const;
        string getCognome() const;
        int getEta() const;
        double* getVoti() const;

        // uno studente e' maggiore di un'altro se ha ma media maggiore
        bool operator>(Studente& s) const;
};

#endif