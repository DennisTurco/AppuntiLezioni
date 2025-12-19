#include "compito.h"

void SpaceAsteroids::carica_partita() {
    for(unsigned i = 0; i < this->altezza; ++i)
        for(unsigned j = 0; j < this->larghezza; ++j)
            schermo[i][j] = 0;

    posizione_astronave = larghezza >> 1;
    energia_rimanente = energia_massima;
    punteggio = 0;
    spostamento_permesso = true;
    laser_permesso = true;
}

SpaceAsteroids::SpaceAsteroids(int altezza, int larghezza, int energia) :
    altezza( (altezza >= min_altezza && altezza <= max_altezza) ? altezza + 1 : max_altezza + 1),
    larghezza( (larghezza >= min_larghezza && larghezza <= max_larghezza && (larghezza & 1u) == 1u) ? larghezza : max_larghezza),
    energia_massima( (energia > 0) ? energia : energia_default) {
    carica_partita();
}

bool SpaceAsteroids::colloca_asteroide(int col) {
    if(col <= 0 || col > larghezza || schermo[1][col-1] != 0)
        return false;

    schermo[1][col-1]++;

    return true;
}

void SpaceAsteroids::avanza_asteroidi() {
    // controllo se avviene una sconfitta
    if (schermo[altezza - 2][posizione_astronave] == 1) {
        carica_partita();
        return;
    }

    // Altrimenti traslo ogni colonna di una riga in basso
    // Notare che questo traslerÃ  anche i laser, dunque dovremo tenerne di conto nella avanza
    for (unsigned j = 0; j < larghezza; ++j) {
        for (unsigned i = altezza - 1; i > 0; --i)
            schermo[i][j] = schermo[i - 1][j];

        schermo[0][j] = 0;
    }

    aumenta_punteggio();
}

ostream& operator<<(ostream& os, const SpaceAsteroids& s) {
    cout << "Punteggio: " << s.punteggio << endl;
    cout << "Record: " << SpaceAsteroids::record << endl;
    cout << "Energia: " << s.energia_rimanente << endl;

    for(unsigned j = 0; j < s.larghezza; ++j)
        os << "_";
    os << endl;

    for(unsigned i = 1; i < s.altezza; ++i) {
        for (unsigned j = 0; j < s.larghezza; ++j) {
            if (s.schermo[i][j] < 0)
                os << "|";
            else if (s.schermo[i][j] > 0)
                os << "X";
            else if (i == s.altezza-1)
                    if(j == s.posizione_astronave)
                        os << "A";
                    else
                        os << "_";
            else
                os << " ";
        }
        os << endl;
    }

    os << endl;

    return os;
}

void SpaceAsteroids::operator<<=(int n){
    if(n<0 || !spostamento_permesso)
        return;

    n = (posizione_astronave > n) ? n : posizione_astronave;

    // controllo della  possibile sconfitta
    for(unsigned j = 1; j <= n; ++j)
        if(schermo[altezza-1][posizione_astronave - j] == 1){
            carica_partita();
            return;
        }

    posizione_astronave -= n;
    spostamento_permesso = false;
}

SpaceAsteroids& SpaceAsteroids::operator|=(int n) {
    if (n <= 0 || !laser_permesso || energia_rimanente == 0)
        return *this;
    
    int intensita = (n <= energia_rimanente) ? n : energia_rimanente;
    energia_rimanente -= n;

    int riga = altezza - 2;
    int colonna = posizione_astronave;

    // caso speciale - asteroide subito sopra
    if (schermo[riga][colonna] == 1) {
        schermo[riga][colonna] = 0;
        aumenta_punteggio();
    } else { // inserimento laser nello schermo
        schermo[riga][colonna] = -intensita;
    }
    
    laser_permesso = false;
    return *this;
}

void SpaceAsteroids::avanza() {
    // avanzamento laser
    for (int i = 0; i < altezza; ++i) {
        for (int j = 0; j < altezza; ++j) {
            if (schermo[i][j] < 0) {
                int intensita = -schermo[i][j];
                schermo[i][j] = 0;

                // caso in cui arriva in alto
                if (i == 1)
                    continue;

                // caso contatto collisione con asteroide
                if (schermo[i-1][j] == 1) { // sto entrando in collisione (i-1)
                    schermo[i-1][j] = 0;
                    intensita--;
                    aumenta_punteggio();
                }

                if (intensita > 0)
                    schermo[i-1][j] = -intensita;
            }
        }
    }

    // recupero energia
    if (energia_rimanente < energia_massima)
        energia_rimanente++;

    // riabilitazione azioni
    spostamento_permesso = true;
    laser_permesso = true;

    avanza_asteroidi();
}

// aggiornamento del punteggio e del record
void SpaceAsteroids::aumenta_punteggio() {
    punteggio++;
    if (punteggio > record) 
        record = punteggio;
}