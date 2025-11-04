#ifndef ESAME_VERSIONE_MIGLIORATA_H
#define ESAME_VERSIONE_MIGLIORATA_H

#include <iostream>
using namespace std;

const int MAX_NAME = 25;

struct utente {
    char nome_utente[MAX_NAME + 1];
    bool prioritario;
    utente* prossimo;
};

class UfficioPostale {
private:
    utente **ufficio;
    int num_sportelli;
    int utenti_totali;
    int utenti_prioritari;
    int utenti_non_prioritari;

    // metodi di supporto privati
    utente* creaNuovoUtente(const char *, bool) const;
    bool numeroSportelliValido(int) const;
    bool nomePresenteInUfficio(const char *) const;
    bool nomeValido(const char *) const;
    int ottieniIndiceSportelloConMenoUtentiPrioritari() const;
public:
    // costruttori e distruttori
    UfficioPostale(int sportelli = 2);
    ~UfficioPostale();

    void accodaUtente(const char*, int);
    bool serviUtente(int);
    void accodaPrioritario(const char*);
    void passaAvanti(const char *, int, int);

    // operatori
    UfficioPostale &operator!();
    friend ostream &operator<<(ostream &os, const UfficioPostale &up);
};

#endif //ESAME_VERSIONE_MIGLIORATA_H
