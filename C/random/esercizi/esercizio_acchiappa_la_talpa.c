#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    srand(time(NULL));
    int serpente_colpito = 0;
    int talpa_colpita = 0
    int pos_serpente;
    int pos_talpa;

    // ricerchiamo 2 posizioni finche' non sono diverse
    do {
        pos_serpente = rand() % 16; // perche' la griglia e' 4x4 quindi 16 posizioni
        pos_talpa = rand() % 16;
    } while (pos_serpente == pos_talpa);

    // TODO: da finire la logica di colpire la talpa
    int colpi = 0;
    while (serpente_colpito == 0 && talpa_colpita == 0 && colpi < 10) {

        printf("Inserire posizione da colpire (0-15)");
        scanf....

        if ....

        colpi++;
    }

    // stampa finale
    if (serpente_colpito == 1) {
        printf("Serpente Colpito! Vince il computer!");
    } else if (talpa_colpita == 1) {
        printf("Talpa Colpita! Vince il giocatore!");
    } else {
        printf("Numero di tentativa massimi raggiunti! Vince il computer!");
    }

    return 0;
}