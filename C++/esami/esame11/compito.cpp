#include <iostream>
#include "compito.h"

using namespace std;

const int soglia_voto_complessivo = 100;

// Costruttore
NRistoranti::NRistoranti(int n) {
    if (n <= 1 || n >= 27)
        N = 2;
    else
        N = n;

    nomi = new char[N];
    char base = 'A';
    for (int i = 0; i < N; i++)
        nomi[i] = base + i;

    matrice = new Valutazione*[N];
    for (int i = 0; i < N; i++) {
        matrice[i] = new Valutazione[N];
        for (int j = 0; j < N; j++) {
            matrice[i][j].location = 0;
            matrice[i][j].servizio = 0;
            matrice[i][j].menu = 0;
            matrice[i][j].conto = 0;
            matrice[i][j].inserita = false;
            matrice[i][j].bonusAggiunto = false;
            matrice[i][j].totaleValutazione = 0;
        }
    }
    M = N;
}

int NRistoranti::indiceRistorante(char nomeRistorante)
{
    int id_ristorante = -1;
    for (int i = 0; i < M; i++)
        if (nomi[i] == n) {
            id_ristorante = i;
            break;
        }
    return id_ristorante;
}

void NRistoranti::aggiungiValutazione(char n, int g, int l, int s, int m, int c) {
    if (n < 'A' || n > 'Z' || g < 1 || g > N || l < 0 || l > 10 || s < 0 || s > 10 || m < 0 || m > 10 || c < 0 || c > 10)
        return;

    int id_ristorante = indiceRistorante(n);
    if (id_ristorante == -1) return;

    Valutazione& v = matrice[id_ristorante][g - 1];
    if (v.inserita) return;

    v.location = l;
    v.servizio = s;
    v.menu = m;
    v.conto = c;
    v.inserita = true;
    v.bonusAggiunto = false;
    v.totaleValutazione = l + s + m + c;
}

void NRistoranti::aggiungiBonus(char nomeRistorante, int bonus) {
    if (bonus < 1 || bonus > 10) return;

    int id_ristorante = indiceRistorante(n);
    if (id_ristorante == -1) return;

    // controlliamo che tutti i giudici hanno votato
    for (int i = 0; i < N; i++) {
        if (!matrice[id_ristorante][i].inserita) {
            return;
        }
    }

    // controllo che il bonus non sia già stato applicato
    if (matrice[id_ristorante][0].bonusAggiunto) return;


    for (int i = 0; i < N; i++) {
        Valutazione& v = matrice[id_ristorante][i];

        int minVal = v.location;
        int minIdx = 0;

        if (v.servizio < minVal) {
            minVal = v.servizio;
            minIdx = 1;
        }
        if (v.menu < minVal) {
            minVal = v.menu;
            minIdx = 2;
        }
        if (v.conto < minVal) {
            minVal = v.conto;
            minIdx = 3;
        }

        switch (minIdx) {
            case 0: // location
                if (v.location + bonus <= 10) v.location += bonus;
                break;
            case 1: // servizio
                if (v.servizio + bonus <= 10) v.servizio += bonus;
                break;
            case 2: // menu
                if (v.menu + bonus <= 10) v.menu += bonus;
                break;
            case 3: // conto
                if (v.conto + bonus <= 10) v.conto += bonus;
                break;
        }

        v.bonusAggiunto = true;
        v.totaleValutazione = v.location + v.servizio + v.menu + v.conto;
    }
}

ostream& operator<<(ostream& os, const NRistoranti& nr) {
    os << nr.M << " ristoranti e " << nr.N << " giudici" << endl;
    for (int i = 0; i < nr.M; i++) {
        int voto_complessivo = 0;
        for (int j = 0; j < nr.N; j++)
            voto_complessivo += nr.matrice[i][j].totaleValutazione;

        os << "- Ristorante " << nr.nomi[i] <<", voto complessivo: " << voto_complessivo << endl;
        for (int j = 0; j < nr.N; j++) {
            const Valutazione& v = nr.matrice[i][j];
            os << "  Giudice " << j + 1 << ":" << endl;
            os << "    Location - " << v.location << endl;
            os << "    Servizio - " << v.servizio << endl;
            os << "    Menu - " << v.menu << endl;
            os << "    Conto - " << v.conto << endl;
        }
    }
    return os;
}
//SECONDA PARTE
NRistoranti::NRistoranti(const NRistoranti& o) {
    N = o.N;
    M = o.M;

    nomi = new char[M];
    for (int i = 0; i < M; i++) {
        nomi[i] = o.nomi[i];
    }

    matrice = new Valutazione*[M];
    for (int i = 0; i < M; i++) {
        matrice[i] = new Valutazione[N];
        for (int j = 0; j < N; j++)
            matrice[i][j] = o.matrice[i][j];
    }
}

NRistoranti::~NRistoranti() {
    delete[] nomi;

    for (int i = 0; i < M; i++) delete[] matrice[i];
    delete[] matrice;
}

NRistoranti& NRistoranti::operator~() {
    for (int i = 0; i < M - 1; i++) { // metto i - 1 perche' sotto faccio i + 1
        int best = i;
        int voto_best = 0;
        for (int j = 0; j < N; j++) {
            voto_best = matrice[i][j].totaleValutazione;
        }

        for (int k = i + 1; k < M; k++) {
            voto_k = 0;
            for (int j = 0; j < N; j++) {
                voto_k = matrice[k][j].totaleValutazione;
            }

            if (voto_k > voto_best || (voto_k == voto_best && nomi[k] > nomi[best])) {
                best = k;
                voto_best = voto_k;
            }
        }

        if (best != i) {
            swap(nomi[i], nomi[best]);
            swap(matrice[i], matrice[best]);
        }
    }
    return *this;
}

NRistoranti NRistoranti::operator!() const {

}