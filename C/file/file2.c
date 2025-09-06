#include <stdlib.h>
#include <stdio.h>

#define FILENAME "test.txt"

void read_from_file(FILE *file) {
    // fgetc/getc fa la lettura dal file di un solo carattere
    char c; 
    while ((c = getc(file)) != EOF) {
        printf("%c", c);
    }
}

int main () {
    // dichiarazione oggetto di tipo FILE
    FILE *file;
    
    ///////////////////////// Scrittura su file
    // apro il file in modalita' write
    file = fopen(FILENAME, "w");

    // scrittura su file
    fprintf(file, "Ciao!\n");
    fprintf(file, "Come Stai?");
    fprintf(file, "&");
    putc('*', file); // scrive un solo carattere nel file

    // chiudo il file
    fclose(file);

    ///////////////////////// Lettura da file
    // apro il file in modalita' read 
    file = fopen(FILENAME, "r");

    // check errore apertura
    if (file == NULL) {
        printf("Errore: file non trovato!");
        return -1;
    }

    read_from_file(file);

    // set the position to the beginning point
    rewind(file);

    printf("\n\nlettura dopo un rewind:\n");
    read_from_file(file);

    // set the position to desire point
    fseek(file, 2, SEEK_SET);

    printf("\n\nlettura dopo un fseek:\n");
    read_from_file(file);

    // chiudo il file
    fclose(file);

    return 0;
}