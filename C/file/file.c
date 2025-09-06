#include <stdio.h>
#include <stdlib.h>

int main () {

    FILE *file;
    file = fopen("test.txt", "r");

    if (file == NULL) {
        printf("Errore apertura file!");
        return -1;
    }

    char carattere;
    int cont = 0;
    while ((carattere = getc(file)) != eof(file)) {
        printf("%c", carattere);
        cont++;
        if (cont == 5) {
            rewind(file);
        }
    }

    fclose(file);
    return 0;
}