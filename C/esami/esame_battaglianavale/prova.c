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

/*
W W W W W
W W A A A
W B W W W
W W W W C
D W W W C

se il file fosse in questo modo lo leggeresti così:
for (int i = 0; i < rows; i++) {
    fscanf(file, "%c %c %c %c %c\n", ...);
}

modo migliore è car dopo char
char ch;
int posx = 0, posy = 0;
while ((ch = fgetc(file)) != EOF) {
    if (ch == ' ' || ch == '\n') {
        // Ignora gli spazi e gestisci il newline
        if (ch == '\n') {
            posx++;
            posy = 0; // Resetta la colonna all'inizio della nuova riga
        }
    } else {
        // Assegna il carattere alla cella corrente
        griglia[posx][posy].codice = ch;

        posy++; // Passa alla colonna successiva
    }
}
*/

#include <stdio.h>
#include <stdlib.h>

const int cols = 5;
const int rows = 5;

struct cella {
    char codice; // codice cella
    int stato; // 0 = nave_colpita (X), 1 = nave_intatta (lascio la lettera), 2 = acqua colpita, 3 = acqua non colpita
};

struct cella** lettura_da_file() {
    FILE *file = fopen("../navi.txt", "r");

    if (file == NULL) {
        printf("Errore: file inesistente!");
        exit(-1);
    }

    // allocazione dinamica per array bidimensionali
    struct cella **griglia = (struct cella**)malloc(rows * sizeof(struct cella*));
    for (int i = 0; i < rows; i++) {
        griglia[i] = (struct cella*)malloc(cols * sizeof(struct cella));
    }

    for (int i = 0; i < rows*cols; i++) {
        char codice;
        int posx, posy;
        fscanf(file, "%c-%d,%d\n", &codice, &posx, &posy);
        griglia[posx][posy].codice = codice;
                
        if (griglia[posx][posy].codice == 'W') griglia[posx][posy].stato = 3; // caso acqua
        else griglia[posx][posy].stato = 1; // caso nave
    }

    fclose(file);

    return griglia;
}

void stampa_griglia_censurata(struct cella **griglia) {
    for (int i = 0; i < rows; i++) {
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
    if (griglia[x][y].stato == 1) {
        griglia[x][y].stato = 0;
    } else if (griglia[x][y].stato == 3) {
        griglia[x][y].stato = 2;
    }
}

int main () {
    struct cella **griglia = lettura_da_file();

    stampa_griglia(griglia);
    printf("\n\n");
    stampa_griglia_censurata(griglia);

    int x,y;
    while(game_over(griglia) == 0) {
        printf("indicami la cella da colpire: ");
        scanf("%d %d", &x, &y);
        sparo(griglia, x, y);
        stampa_griglia_censurata(griglia);
    }

    free(griglia);
    return 0;
}