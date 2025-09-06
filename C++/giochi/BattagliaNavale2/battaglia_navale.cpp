#include "battaglia_navale.h"

// resetta la griglia di gioco
void reset_griglia(int griglia[DIM][DIM]) {
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            griglia[i][j] = 0;
        }
    }
}

// serve a calcolare la somma totale delle caselle della griglia per capire se la generazione e' corretta
int somma_totale(int griglia[DIM][DIM]) {
    int somma = 0;
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            somma += griglia[i][j];
        }
    }
    return somma;
}

// stampa la griglia di gioco senza mostrare le caselle con le navi
void stampa_matrice(int griglia[DIM][DIM]) {
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            if (griglia[i][j] == -1) {
                cout << "* ";
            }
            else {
                cout << "o ";
            }
        }
        cout << endl;
    }
}

// ritorna true se il contatore "posizioni_rimaste" e' = a 1, altrimenti false
// questa funzione serve per capire se nel main voglio stampare "colpita" o "affondata"
bool nave_affondata(int griglia[DIM][DIM], int nave) {
    int posizioni_rimaste = 0;
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            if (griglia[i][j] == nave) {
                posizioni_rimaste++;
            }
        }
    }

    if (posizioni_rimaste == 1) {
        return true;
    } else {
        return false;
    }
}

// generazione griglia di gioco
void genera_griglia(int griglia[DIM][DIM]) {
    srand(time(NULL));
    int x, y;
    int direzione; //0=destra,1=sotto,2=sinistra,3=alto
    do {
        reset_griglia(griglia);

        for(int i = 1; i <= 5; i++) {
            x = rand() % DIM;
            y = rand() % DIM;
            direzione = rand() % 4;

            griglia[x][y] = i;

            for(int j = 1; j < i; j++) {
                // le condizioni qui sotto servono per capire in quale direzione spostarsi e se è possibile farlo (talvolta se sono al bordo non posso piu' spostarmi)
                if(direzione == 0 && y + j < DIM) {
                    griglia[x][y + j] = i; // perchè cambia la direzione di y spostandoci a destra di j volte
                } else if(direzione == 1 && x + j < DIM) {
                    griglia[x + j][y] = i; // per andare sotto
                } else if(direzione == 2 && y - j >= 0) {
                    griglia[x][y - j] = i; // per andare a sinistra
                } else if(x - j >= 0) {
                    griglia[x - j][y] = i; // per andare sopra
                } else {
                    break; // se lo spostamento non va bene, ricominciamo
                }
            }
        }
    } while(somma_totale(griglia) != 55);
}