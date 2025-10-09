#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int elemento1_x, elemento1_y;
    int elemento2_x, elemento2_y;
    int estrazione1_x, estrazione1_y;
    int estrazione2_x, estrazione2_y;
    int tentativi = 0;

    // genera due posizioni diverse
    do {
        elemento1_x = rand() % 4 + 1;
        elemento1_y = rand() % 4 + 1;
        elemento2_x = rand() % 4 + 1;
        elemento2_y = rand() % 4 + 1;
    } while (elemento1_x == elemento2_x && elemento1_y == elemento2_y);

    int continuare = 1;
    while (continuare == 1) {
        tentativi++;

        printf("\nTentativo %d di 5\n", tentativi);
        printf("Inserisci la prima coordinata (riga,colonna): ");
        scanf("%d%*c%d", &estrazione1_x, &estrazione1_y);
        printf("Inserisci la seconda coordinata (riga,colonna): ");
        scanf("%d%*c%d", &estrazione2_x, &estrazione2_y);

        if (estrazione1_x == estrazione2_x && estrazione1_y == estrazione2_y) {
            printf("Hai inserito la stessa posizione due volte! Riprova.\n");
            tentativi--;
            continue;
        }

        // controllo di vittoria (entrambe trovate, in qualsiasi ordine)
        if (
            (estrazione1_x == elemento1_x && estrazione1_y == elemento1_y &&
             estrazione2_x == elemento2_x && estrazione2_y == elemento2_y)
         ||
            (estrazione1_x == elemento2_x && estrazione1_y == elemento2_y &&
             estrazione2_x == elemento1_x && estrazione2_y == elemento1_y)
        ) {
            printf("Hai vinto! Hai trovato entrambe le X!\n");
            continuare = 0;
        }
        else if (
            (estrazione1_x == elemento1_x && estrazione1_y == elemento1_y) ||
            (estrazione1_x == elemento2_x && estrazione1_y == elemento2_y) ||
            (estrazione2_x == elemento1_x && estrazione2_y == elemento1_y) ||
            (estrazione2_x == elemento2_x && estrazione2_y == elemento2_y)
        ) {
            printf("Hai trovato una X, ma non entrambe!\n");
        }
        else {
            printf("Nessuna X trovata.\n");
        }

        if (tentativi >= 5 && continuare == 1) {
            printf("\nHai perso! Tentativi esauriti.\n");
            printf("Le X erano in (%d,%d) e (%d,%d)\n", elemento1_x, elemento1_y, elemento2_x, elemento2_y);
            continuare = 0;
        }
    }

    return 0;
}
