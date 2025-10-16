/*
Scrivere un programma C++ che gestisce un piccolo database di studenti, con le seguenti funzionalità:
1. Inserimento dati studenti (nome, cognome, età, voti).
2. Visualizzazione degli studenti e della loro media.
3. Ricerca di uno studente per nome.
4. Funzioni per calcolare la media dei voti.
5. Ordinamento degli studenti in base alla media.
6. Definizione di una classe Studente con operatori per confrontare le medie
*/

#include <iostream>
#include "studente.h"
#include "servizio_studenti.h"
using namespace std;

int main () {

    const int NUM_STUDENTI = 3;
    double voti[NUM_STUDENTI][3];
    string nomi[NUM_STUDENTI];
    string cognomi[NUM_STUDENTI];
    int eta[NUM_STUDENTI];

    // dati studenti
    for (int i = 0; i < NUM_STUDENTI; i++) {
        cout << "Studente " << i + 1 << endl;
        cout << "Nome: ";
        cin >> nomi[i];
        cout << "Cognome: ";
        cin >> cognomi[i];
        cout << "Età: ";
        cin >> eta[i];
        for (int j = 0; j < 3; j++) {
            cout << "Voto " << j + 1 << ": ";
            cin >> voti[i][j];
        }
        cout << "------------------" << endl;
    }

    Studente studentiArray[NUM_STUDENTI] = {
        Studente(nomi[0], cognomi[0], eta[0], voti[0]),
        Studente(nomi[1], cognomi[1], eta[1], voti[1]),
        Studente(nomi[2], cognomi[2], eta[2], voti[2]),
        Studente(nomi[3], cognomi[3], eta[3], voti[3]),
        Studente(nomi[4], cognomi[4], eta[4], voti[4]),
        Studente(nomi[5], cognomi[5], eta[5], voti[5]),
        Studente(nomi[6], cognomi[6], eta[6], voti[6]),
        Studente(nomi[7], cognomi[7], eta[7], voti[7]),
        Studente(nomi[8], cognomi[8], eta[8], voti[8]),
        Studente(nomi[9], cognomi[9], eta[9], voti[9])
    };

    ServizioStudenti servizio(studentiArray);

    cout << "\nLista studenti: " << endl;
    servizio.stampaStudenti();

    string nomeRicerca;
    cout << "\nInserisci il nome dello studente da cercare: ";
    cin >> nomeRicerca;
    Studente trovato = servizio.ricercaStudentePerNome(nomeRicerca);
    cout << "Studente trovato:\n";
    trovato.stampa();

    servizio.ordinaStudentiPerMedia();
    cout << "\nStudenti ordinati per media: " << endl;
    servizio.stampaStudenti();

    return 0;
}