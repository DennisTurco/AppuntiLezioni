#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Esercizio preso dal pdf "Compiti vacanze estive"

int main() {
    srand(time(NULL));

    int punteggio1 = 0;
    int punteggio2 = 0;

    int continuare_giocatore1 = 1; // 1 se continuare, 0 se non continuare
    int continuare_giocatore2 = 1;

    int scelta;
    int d1, d2;
    int turno = 1; // inizialmente tocca a 1
    while (continuare_giocatore1 == 1 || continuare_giocatore2 == 1) {
        if (turno == 1) {
            printf("Tocca al giocatore 1: ");
        } else {
            printf("Tocca al giocatore 2: ");
        }

        printf("Vuoi lanciare ancora (0 = no/1 = si)? ");
        scanf("%d", &scelta);

        d1 = rand() % 6 + 1;
        d2 = rand() % 6 + 1;

        if (turno == 1) {                           // turno giocatore 1
            if (scelta == 1) {
                if (d1 != d2) {
                    punteggio1++;
                } else if (d1 == 1 && d2 == 1) {
                    punteggio1 = 0;
                    continuare_giocatore1 = 0;
                } else {
                    punteggio1 = 0;
                }
            } else {
                continuare_giocatore1 = 0;
            }
        } else {                                    // turno giocatore 2
            if (scelta == 1) {
                if (d1 != d2) {
                    punteggio2++;
                } else if (d1 == 1 && d2 == 1) {
                    punteggio2 = 0;
                    continuare_giocatore2 = 0;
                } else {
                    punteggio2 = 0;
                }
            } else {
                continuare_giocatore2 = 0;
            }
        }

        printf("dadi estratti: %d - %d. Punteggio = %d\n", d1, d2, punteggio1);

        // invertiamo il turno dei giocatori
        if (turno == 1 && continuare_giocatore2 == 1) {
            turno = 2;
        } else if (turno == 2 && continuare_giocatore1 == 1) {
            turno = 1;
        }
    }

    if (punteggio1 > punteggio2) {
        printf("Vince il giocatore 1 con punteggio finale di %d - %d", punteggio1, punteggio2);
    } else if (punteggio1 < punteggio2) {
        printf("Vince il giocatore 2 con punteggio finale di %d - %d", punteggio1, punteggio2);
    } else {
        printf("Parita' con punteggio finale di %d - %d", punteggio1, punteggio2);
    }

    return 0;
}