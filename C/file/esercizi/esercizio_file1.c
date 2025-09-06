#include <stdio.h>
#include <stdlib.h>
#define PERCORSO "./test.txt"

/*
    ESERCIZIO: creaiamo un file e ci scriviamo dentro 3 caratteri: A, B, C.
    Lo apriamo in modalità lettura e ne leggiamo il contenuto carattere per carattere per poi stamparlo a video
*/

int main () {
    FILE *file;

    // #################### Scrittura nel file
    // apertura del file
    file = fopen(PERCORSO, "w"); // apro il file in modalita' scrittura

    // scrittura nel file
    fprintf(file, "ABC\n");
    fputs("ABC\n", file);
    putc('A', file);
    putc('B', file);
    putc('C', file);

    // chiusura del file
    fclose(file);

    // #################### Lettura dal file
    // apertura del file 
    file = fopen(PERCORSO, "r");

    // caso di errore
    if (file == NULL) {
        printf("Errore nell'aperturea del file...");
        return -1;
    }

    // lettura di un carattere per volta
    char carattere;
    while ((carattere = getc(file)) != eof(file)) { // EOF() serve per capire se ho raggiunto la fine del file
        printf("%c", carattere);
    }

    // equivalente a:
    // do {
    //     carattere = getc(file);
    //     printf("%c", carattere);
    // } while (carattere != EOF())

    // chiusura del file
    fclose(file);

    return 0;
}