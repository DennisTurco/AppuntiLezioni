#ifndef ESAME_H
#define ESAME_H

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
public:
    UfficioPostale(int sportelli = 2);
    void accodaUtente(const char*, int);
    bool serviUtente(int);
    void accodaPrioritario(const char*);
    void passaAvanti(const char *, int, int);
    ~UfficioPostale();

    UfficioPostale &operator!();
    friend ostream &operator<<(ostream &os, const UfficioPostale &up);
};

#endif //ESAME_H