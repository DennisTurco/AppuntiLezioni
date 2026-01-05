#include "compito.h"
Metropolitana::Metropolitana() {
    for(int i=0; i<num_stazioni; ++i){
        for (int j = 0; j < num_stazioni; ++j)
            grafo[i][j] = false;
        stazioni[i].utenti = 0;
        stazioni[i].presenza_treno = false;
    }
}

Metropolitana& Metropolitana::aggiungi_connessione(int s1, int s2) {
    // caso di uscita per errore nell'input
    if (s1 == s2 || s1 <= 0 || s2 <= 0 || s1 > num_stazioni || s2 > num_stazioni)
        return *this;

    // nell'array contiamo da 0 e non da 1
    s1--;
    s2--;

    // collegamento bidirezionale tra le 2 stazioni
    grafo[s1][s2] = true;
    grafo[s2][s1] = true;

    return *this;
}

bool Metropolitana::aggiungi_treno(int capienza, int num_stazione) {
    if (capienza <= 0 || capienza > max_capienza || num_stazione <= 0 || num_stazione > num_stazioni)
        return false;

    // nell'array contiamo da 0 e non da 1 (num_stazione - 1)
    // salvo il risultato in un riferimento perchè in caso di errore non cambiamo nulla
    stazione& s = stazioni[num_stazione - 1];

    // verifichiamo la presenza di un nuovo treno
    if (s.presenza_treno)
        return false;

    // creazione del treno
    s.presenza_treno = true;
    s.capienza = capienza;
    s.posti_liberi = capienza;

    carica_treno(&s);

    return true;
}

bool Metropolitana::muovi_treno(int quanti_scendono, int s1, int s2) {
    if (s1 == s2 || s1 <= 0 || s2 <= 0 || s1 > num_stazioni || s2 > num_stazioni)
        return false;

    s1--;
    s2--;

    if (!grafo[s1][s2]) return false; // caso in cui le stazioni non sono collegate
    if (!stazioni[s1].presenza_treno) return false; // caso in cui nella stazione s1 non c'e' il treno
    if (stazioni[s2].presenza_treno) return false;

    stazione& from = stazioni[s1];
    stazione& to = stazioni[s2];

    int a_bordo = from.capienza - from.posti_liberi;
    if (quanti_scendono < 0) quanti_scendono = 0;
    if (quanti_scendono > a_bordo) quanti_scendono = a_bordo;

    if (quanti_scendono + to.utenti > max_utenti)
        return false;

    // spostamento fisico del treno
    to = from;
    from.presenza_treno = false;

    // carico scarico
    scarica_treno(quanti_scendono, &to);
    carica_treno(&to);

    return true;
}

bool Metropolitana::rimuovi_treno(int num_stazione) {
    if (num_stazione <= 0 || num_stazione > num_stazioni)
        return false;

    stazione& s = stazioni[num_stazione - 1];

    if (!s.presenza_treno)
        return false;

    int passeggeri = s.capienza - s.posti_liberi;
    if (s.utenti + passeggeri > max_utenti)
        return false;

    s.utenti += passeggeri;
    s.presenza_treno = false;
    return true;
}

ostream& operator<<(ostream& os, const Metropolitana& m) {
    for (int i = 0; i < num_stazioni; ++i){
        if(m.stazioni[i].utenti<10)
            os<<' ';
        os << m.stazioni[i].utenti<<' ';
        if (m.stazioni[i].presenza_treno) {
            if (m.stazioni[i].capienza<10)
                os << ' ';
            os << m.stazioni[i].capienza << ' ';
            if (m.stazioni[i].posti_liberi<10)
                os << ' ';
            os << m.stazioni[i].posti_liberi;
        }
        else
            os << " X  X";
        os<<endl;
    }

    os<<endl;
    for(int i=1; i<=num_stazioni; ++i)
        for(int j=i+1; j<=num_stazioni; ++j)
            if(m.grafo[i-1][j-1])
                os<<i<<" <-> "<<j<<"  ";

    os<<endl;
    return os;
}

int Metropolitana::aggiungi_utenti(int quanti, int staz) {
    if(quanti<=0 || staz<=0 || staz > num_stazioni)
        return 0;

    stazione* s = &stazioni[--staz];

    int rimanenti = quanti;
    if(s->presenza_treno) {
        if (s->posti_liberi >= quanti) {
            s->posti_liberi -= quanti;
            return quanti;
        }
        rimanenti -= s->posti_liberi;
        s->posti_liberi = 0;
    }
    int eccesso = s->utenti+rimanenti-max_utenti;

    if(eccesso<=0){
        s->utenti += rimanenti;
        return quanti;
    }

    s->utenti = max_utenti;
    return quanti-eccesso;
}

void Metropolitana::scarica_treno(int quanti, stazione* s) {
	if(quanti<=0)
        return;
    if(quanti>s->capienza-s->posti_liberi)
        s->posti_liberi = s->capienza;
    else
        s->posti_liberi += quanti;
}

void Metropolitana::carica_treno(stazione* s) {
    int quanti = s->utenti;
    if(quanti > s->posti_liberi)
        quanti = s->posti_liberi;

    s->utenti -= quanti;
    s->posti_liberi -= quanti;
}
int Metropolitana::operator!() const {

    int delta = 0;
    for(int i=0; i<num_stazioni; ++i) {
        if (stazioni[i].presenza_treno)
            delta -= stazioni[i].posti_liberi;
        delta += stazioni[i].utenti;
    }

    return delta;
}

Metropolitana& Metropolitana::operator++() {
    for(int i=0; i<num_stazioni; ++i)
        if(stazioni[i].utenti<max_utenti){
            if(!stazioni[i].presenza_treno || stazioni[i].posti_liberi==0)
                stazioni[i].utenti++;
            else
                stazioni[i].posti_liberi--;
        }

    return *this;
}