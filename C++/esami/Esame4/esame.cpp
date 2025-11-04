#include "esame.h"
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
        os << endl;
        os << "- Sportello " << i + 1 << ": ";
        for (utente *p = up.ufficio[i]; p != nullptr; p = p->prossimo) {
            os << p->nome_utente;
            if (p->prioritario)
                os << " " << "(P)";
            if (p->prossimo != nullptr)
                os << ", ";
        }
    }
    return os;
}

void UfficioPostale::accodaUtente(const char *nome, int sportello) {
    if (sportello < 1 || sportello > num_sportelli)
        return;
    if (strlen(nome) > MAX_NAME || strlen(nome) == 0)
        return;
    utente *p, *q;
    for (p = ufficio[sportello - 1]; p != nullptr; p = p->prossimo) {
        if (strcmp(nome, p->nome_utente) == 0)
            return;
        q = p;
    }

    p = new utente;
    strcpy(p->nome_utente, nome);
    p->prioritario = false;
    p->prossimo = nullptr;

    if (ufficio[sportello - 1] == nullptr)
        ufficio[sportello - 1] = p;
    else
        q->prossimo = p;
    utenti_totali++;
    utenti_non_prioritari++;
}

bool UfficioPostale::serviUtente(int sportello) {
    if (sportello < 1 || sportello > num_sportelli)
        return false;
    if (ufficio[sportello - 1] == nullptr)
        return false;
    utente *p = ufficio[sportello - 1]->prossimo;
    utenti_totali--;
    if (ufficio[sportello - 1]->prioritario)
        utenti_prioritari--;
    else
        utenti_non_prioritari--;
    delete ufficio[sportello - 1];
    ufficio[sportello - 1] = p;
    return true;
}

void UfficioPostale::accodaPrioritario(const char* nome) {
    if (strlen(nome) > MAX_NAME || strlen(nome) == 0)
        return;

    // controllo che il nome non esista in nessuno sportello
    // -> esco dal metodo se il nome e' gia' presente
    for (int i = 0; i < num_sportelli; i++) {
        for (utente *p = ufficio[i]; p != nullptr; p = p->prossimo) { // puoi anche farlo come il while del distruttore
            if (strcmp(p->nome_utente, nome) == 0) {
                return;
            }
        }
    }

    // trovare lo sportello con meno utenti prioritari
    int min_prior = 9999;
    int indice = 0;
    for (int i = 0; i < num_sportelli; i++) {
        int count = 0;
        for (utente *p = ufficio[i]; p != nullptr; p = p->prossimo) {
            if (p->prioritario) {
                count++;
            }
        }

        if (count < min_prior) {
            min_prior = count;
            indice = i;
        }
    }

    utente *nuovo = new utente;
    strcpy(nuovo->nome_utente, nome);
    nuovo->prioritario = true;
    nuovo->prossimo = nullptr;

    utente* p = ufficio[indice];
    utente *last_prior = nullptr;
    while (p != nullptr) {
        if (p-> prioritario) {
            last_prior = p; // quando il ciclo sara' finito, conoscero' l'ultimo prioritario e quindi piazzo il nuovo dietro l'ultimo
        }
        p = p->prossimo;
    }

    if (last_prior == nullptr)  { // caso in cui nessun utente prioritario
        nuovo->prossimo = ufficio[indice];
        ufficio[indice] = nuovo;
    }
    else {
        nuovo->prossimo = last_prior->prossimo;
        last_prior->prossimo = nuovo;
    }

    utenti_totali++;
    utenti_prioritari++;
}

void UfficioPostale::passaAvanti(const char *nome, int sportello, int pos) {
    if (sportello < 1 || sportello > num_sportelli) return;
    if (pos <= 0) return;
    if (strlen(nome) == 0 || strlen(nome) > 25) return;

    utente *head = ufficio[sportello - 1];
    if (head == nullptr) return;

    // trova utente e precedente
    utente *p = head, *prev = nullptr;
    int index = 0;
    while (p != nullptr && strcmp(p->nome_utente, nome) != 0) {
        prev = p;
        p = p->prossimo;
        index++;
    }
    if (p == nullptr) return; // non trovato

    // calcola lunghezza coda
    int len = 0;
    for (utente *tmp = head; tmp != nullptr; tmp = tmp->prossimo) len++;
    if (pos >= len) return;

    // rimuovi p dalla lista
    if (prev == nullptr)
        ufficio[sportello - 1] = p->prossimo;
    else
        prev->prossimo = p->prossimo;

    // calcola nuova posizione
    int newPos = index - pos;
    if (newPos < 0) newPos = 0;

    // se è non prioritario e supera almeno un prioritario, diventa prioritario
    if (!p->prioritario) {
        int passed_prio = 0;
        int i = 0;
        for (utente *q = head; q != nullptr && i < index; q = q->prossimo, i++) {
            if (i >= newPos && q->prioritario) {
                passed_prio = 1;
                break;
            }
        }
        if (passed_prio) {
            p->prioritario = true;
            utenti_prioritari++;
            utenti_non_prioritari--;
        }
    }

    // inserisci p nella nuova posizione
    if (newPos == 0) {
        p->prossimo = ufficio[sportello - 1];
        ufficio[sportello - 1] = p;
    } else {
        utente *q = ufficio[sportello - 1];
        int i = 0;
        while (q != nullptr && i < newPos - 1) {
            q = q->prossimo;
            i++;
        }
        if (q == nullptr) return;
        p->prossimo = q->prossimo;
        q->prossimo = p;
    }
}

UfficioPostale::~UfficioPostale() {
    for (int i = 0; i < num_sportelli; i++) {
        utente* p = ufficio[i];
        while(p != nullptr) {
            p = p -> prossimo;
            serviUtente(i + 1);

            /*
            Possibile farlo anche cosi':

            utente* next = p->prossimo;
            delete p;
            p = next;
            */
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