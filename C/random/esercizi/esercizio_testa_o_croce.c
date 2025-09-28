/*
L'utente sceglie testa o croce.
Si genera a caso testa o croce.
Se l'utente ha indovinato prende un punto, altrimenti lo prende il pc.
Vince il primo che indovina 5 volte.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int punteggio_utente = 0;
    int punteggio_cpu = 0;

    int scelta;
    while (punteggio_utente != 5 && punteggio_cpu != 5) {
        printf("Testa o croce (0/1): ");
        scanf("%d", &scelta);

        int estrazione = rand() % 2;

        if (scelta == estrazione) {
            punteggio_utente++;
            printf("punto all'utente\n");
        } else {
            punteggio_cpu++;
            printf("punto alla cpu\n");
        }
    }

    if (punteggio_utente == 5) {
        printf("Vince l'utente");
    } else {
        printf("Vince la cpu");
    }

    return 0;
}