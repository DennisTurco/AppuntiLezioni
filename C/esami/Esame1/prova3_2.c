/* Testo possibile:
    data una griglia 5x5 gestita da un array dinamico (bidimensionale)
    la posizione delle navi nella griglia viene indica su un file navi.txt.
    Il giocatore continua a fornire la posizione di una casella e il programma risponde dicendo
    se la nave è stata colpita, affondata o mancata.
    Ad ogni colpo sparato viene ristampata la griglia aggiornata.
    N.B.: per ogni nave occorre salvare uno stato associato (struct) con campi: codice, grandezza, stato, posx, posxy.
    Sono necessarie le seguenti funzioni:
    1. lettura -> per leggere il file e ottenere tutte le info
    2. stampa -> per stampare la griglia
    3. aggiorna -> per aggiornare la griglia dopo ogni sparo
    4. funzione per capire se il gioco è finito
*/

/* stampa a celle scoperte
W W W W W
W W W W W
W W A A A
W B W W W
W W W W C
D W W W C
*/

// usiamo la struct e il codice della nave per avere distinzione se il 
// colpire la nave da come risultato l'affondare di essa o no

#include <stdio.h>
#include <stdlib.h>

const int cols = 5;
const int rows = 5;

struct cella {
    char codice; // codice cella
    int stato; // 0 = nave_colpita (X), 1 = nave_intatta (lascio la lettera), 2 = acqua colpita, 3 = acqua non colpita
};

struct cella** lettura_griglia_da_file(FILE *file) {
    // allocazione dinamica per array bidimensionali
    struct cella **griglia = (struct cella**)malloc(rows * sizeof(struct cella*));
    for (int i = 0; i < rows; i++) {
        griglia[i] = (struct cella*)malloc(cols * sizeof(struct cella));
    }

    char ch;
    char codice;
    int posx, posy;
    do {
        fscanf(file, "%c-%d,%d", &codice, &posx, &posy);

        griglia[posx][posy].codice = codice;
        if (griglia[posx][posy].codice == 'W') griglia[posx][posy].stato = 3; // caso acqua
        else griglia[posx][posy].stato = 1; // caso nave

        ch = fgetc(file);

    } while(ch != '\n'); // ch sarà o ';' o '\n', se è '\n' ho terminato la linea

    return griglia;
}

void stampa_griglia_censurata(struct cella **griglia) {
    printf("  0 1 2 3 4\n");
    for (int i = 0; i < rows; i++) {
        printf("%c ", i+48+17); 
        for (int j = 0; j < cols; j++) {
            if (griglia[i][j].stato == 0) printf("X ");
            else if (griglia[i][j].stato == 1 || griglia[i][j].stato == 3) printf("* ");
            else if (griglia[i][j].stato == 2) printf("0 ");
        }

        printf("\n");
    }
}

void stampa_griglia(struct cella **griglia) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (griglia[i][j].stato == 0) printf("X ");
            else if (griglia[i][j].stato == 1) printf("%c ", griglia[i][j].codice);
            else if (griglia[i][j].stato == 2) printf("0 ");
            else if (griglia[i][j].stato == 3) printf("* ");
        }

        printf("\n");
    }
}

// ritorna 0 se non è finito
// 1 altrimenti
int game_over(struct cella **griglia) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (griglia[i][j].stato == 1){
                return 0;
            }
        }
    }

    return 1;
}

void sparo(struct cella **griglia, int x, int y) {
    if (x > rows || x < 0 || y > cols || y < 0) {
        printf("ERRORE: Coordinate non valide!\n");
        return;
    }
    
    if (griglia[x][y].stato == 1 || griglia[x][y].stato == 0) {
        griglia[x][y].stato = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (griglia[i][j].codice == griglia[x][y].codice && griglia[i][j].stato == 1) {
                    printf("Colpita!!\n");
                    return;
                }
            }
        }
        printf("Colpita e Affondata!!\n");
    } else if (griglia[x][y].stato == 3 || griglia[x][y].stato == 2) {
        griglia[x][y].stato = 2;
        printf("Acqua...\n");
    }
}

void simula(FILE *file, struct cella **griglia_giocatore1, struct cella **griglia_giocatore2) {
    char ch;
    int posx, posy;
    int turno = 1;
    do {
        fscanf(file, "%d,%d", &posx, &posy);
        printf("\n");

        // logica sparo
        if (turno == 1) {
            sparo(griglia_giocatore2, posx, posy);
            printf("Il giocatore 1 ha sparato in posizione %d,%d\n", posx, posy);
            // stampa_griglia_censurata(griglia_giocatore2);
            int res = game_over(griglia_giocatore2);
            if (res == 1) {
                printf("Giocatore 1 ha vinto!\n");
                return;
            }
        }
        else if (turno == 2) {
            sparo(griglia_giocatore1, posx, posy);
            printf("Il giocatore 2 ha sparato in posizione %d,%d\n", posx, posy);
            // stampa_griglia_censurata(griglia_giocatore1);
            int res = game_over(griglia_giocatore1);
            if (res == 1) {
                printf("Giocatore 2 ha vinto!\n");
                return;
            }
        }

        printf("Giocatore1:\n");
        stampa_griglia_censurata(griglia_giocatore1);
        printf("Giocatore2:\n");
        stampa_griglia_censurata(griglia_giocatore2);

        // cambio turno
        if (turno == 1) turno = 2;
        else if (turno == 2) turno = 1;

        ch = fgetc(file); // ' ' o EOF

    } while(ch != EOF);
}

int main () {
    FILE *file = fopen("../navi_2.txt", "r");
    if (file == NULL) {
        printf("Errore: file inesistente!");
        exit(-1);
    }
    struct cella **griglia_giocatore1 = lettura_griglia_da_file(file);
    struct cella **griglia_giocatore2 = lettura_griglia_da_file(file);
    simula(file, griglia_giocatore1, griglia_giocatore2);
    fclose(file);

    free(griglia_giocatore1);
    free(griglia_giocatore2);
    return 0;
}