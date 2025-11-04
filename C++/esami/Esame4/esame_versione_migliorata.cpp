#include "esame_versione_migliorata.h"
#include <cstring>

UfficioPostale::UfficioPostale(int sportelli) {
    if (sportelli < 1)
        sportelli = 2;

    num_sportelli = sportelli;
    utenti_totali = 0;
    utenti_prioritari = 0;
    utenti_non_prioritari = 0;

    ufficio = new utente *[num_sportelli];
    for (int i = 0; i < num_sportelli; i++)
        ufficio[i] = nullptr;
}

ostream &operator<<(ostream &os, const UfficioPostale &up) {
    os << "Utenti totali: " << up.utenti_totali << endl;
    os << "Prioritari: " << up.utenti_prioritari;

    for (int i = 0; i < up.num_sportelli; i++) {
        os << endl << "- Sportello " << i + 1 << ": ";
        for (utente *p = up.ufficio[i]; p != nullptr; p = p->prossimo) {
            os << p->nome_utente;
            if (p->prioritario) os << " " << "(P)";
            if (p->prossimo != nullptr) os << ", ";
        }
    }
    return os;
}

void UfficioPostale::accodaUtente(const char *nome, int sportello) {
    if (!numeroSportelliValido(sportello) || !nomeValido(nome) || nomePresenteInUfficio(nome))
        return;

    utente *nuovo = creaNuovoUtente(nome, false);
    utente *ultimo = ufficio[sportello - 1];

    if (!ultimo)
        ufficio[sportello - 1] = nuovo;
    else {
        while (ultimo->prossimo)
            ultimo = ultimo->prossimo;
        ultimo->prossimo = nuovo;
    }

    utenti_totali++;
    utenti_non_prioritari++;
}

bool UfficioPostale::serviUtente(int sportello) {
    if (!numeroSportelliValido(sportello)) return false;

    utente *primo = ufficio[sportello - 1];
    if (!primo) return false;

    ufficio[sportello - 1] = primo->prossimo;

    utenti_totali--;
    if (primo->prioritario) utenti_prioritari--;
    else utenti_non_prioritari--;

    delete primo;
    return true;
}

void UfficioPostale::accodaPrioritario(const char* nome) {
    if (!nomeValido(nome) || nomePresenteInUfficio(nome))
        return;

    int indice = ottieniIndiceSportelloConMenoUtentiPrioritari();
    utente *nuovo = creaNuovoUtente(nome, true);

    // Trova ultimo prioritario
    utente *p = ufficio[indice];
    utente *ultimo_prior = nullptr;
    while (p) {
        if (p->prioritario) ultimo_prior = p;
        p = p->prossimo;
    }

    if (!ultimo_prior) { // nessun prioritario
        nuovo->prossimo = ufficio[indice];
        ufficio[indice] = nuovo;
    } else {
        nuovo->prossimo = ultimo_prior->prossimo;
        ultimo_prior->prossimo = nuovo;
    }

    utenti_totali++;
    utenti_prioritari++;
}

void UfficioPostale::passaAvanti(const char *nome, int sportello, int pos) {
    if (!numeroSportelliValido(sportello) || pos <= 0 || !nomeValido(nome))
        return;

    utente *head = ufficio[sportello - 1];
    if (!head) return;

    utente *p = head, *prev = nullptr;
    int index = 0;
    while (p && strcmp(p->nome_utente, nome) != 0) {
        prev = p;
        p = p->prossimo;
        index++;
    }
    if (!p) return; // non trovato

    // Rimuovi dalla posizione corrente
    if (!prev) ufficio[sportello - 1] = p->prossimo;
    else prev->prossimo = p->prossimo;

    // Calcola nuova posizione
    int newPos = max(0, index - pos);

    utente *q = ufficio[sportello - 1];
    if (!q || newPos == 0) {
        p->prossimo = q;
        ufficio[sportello - 1] = p;
        return;
    }

    int i = 0;
    while (q->prossimo && i < newPos - 1) {
        q = q->prossimo;
        i++;
    }

    p->prossimo = q->prossimo;
    q->prossimo = p;
}

UfficioPostale::~UfficioPostale() {
    for (int i = 0; i < num_sportelli; i++) {
        utente *p = ufficio[i];
        while(p != nullptr) {
            utente* next = p->prossimo;
            delete p;
            p = next;
        }
    }
    delete[] ufficio;
}

UfficioPostale &UfficioPostale::operator!() {
    for (int i = 0; i < num_sportelli; i++) {
        utente *p = ufficio[i];
        utente *prio_head = nullptr, *prio_tail = nullptr;
        utente *non_head = nullptr, *non_tail = nullptr;

        while (p != nullptr) {
            utente *next = p->prossimo;
            p->prossimo = nullptr;
            p->prioritario = !p->prioritario; // inverte
            if (p->prioritario) {
                if (prio_head == nullptr) prio_head = p;
                else prio_tail->prossimo = p;
                prio_tail = p;
            } else {
                if (non_head == nullptr) non_head = p;
                else non_tail->prossimo = p;
                non_tail = p;
            }
            p = next;
        }
        if (prio_tail != nullptr)
            prio_tail->prossimo = non_head;
        else
            prio_head = non_head;

        ufficio[i] = prio_head;
    }

    // aggiorna contatori
    utenti_prioritari = 0;
    utenti_non_prioritari = 0;
    for (int i = 0; i < num_sportelli; i++) {
        for (utente *p = ufficio[i]; p != nullptr; p = p->prossimo) {
            if (p->prioritario) utenti_prioritari++;
            else utenti_non_prioritari++;
        }
    }
    return *this;
}

// -------------------- Metodi di supporto privati

bool UfficioPostale::nomeValido(const char *nome) const {
    return (nome && strlen(nome) > 0 && strlen(nome) <= MAX_NAME);
}

bool UfficioPostale::numeroSportelliValido(int sportello) const {
    return (sportello >= 1 && sportello <= num_sportelli);
}

bool UfficioPostale::nomePresenteInUfficio(const char *nome) const {
    for (int i = 0; i < num_sportelli; i++) {
        for (utente *p = ufficio[i]; p != nullptr; p = p->prossimo)
            if (strcmp(p->nome_utente, nome) == 0)
                return true;
    }
    return false;
}

utente* UfficioPostale::creaNuovoUtente(const char *nome, bool prioritario) const {
    utente *nuovo = new utente;
    strcpy(nuovo->nome_utente, nome);
    nuovo->prioritario = prioritario;
    nuovo->prossimo = nullptr;
    return nuovo;
}

int UfficioPostale::ottieniIndiceSportelloConMenoUtentiPrioritari() const {
    int min_prior = INT_MAX;
    int indice = 0;

    for (int i = 0; i < num_sportelli; i++) {
        int count = 0;
        for (utente *p = ufficio[i]; p != nullptr; p = p->prossimo)
            if (p->prioritario) count++;

        if (count < min_prior) {
            min_prior = count;
            indice = i;
        }
    }
    return indice;
}
