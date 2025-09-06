#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 una stringa è una sequenza di caratteri.
 In particolare e' una "parola" o una "frase".

 es:
    "esempio",
    "ciao come stai?"

 ogni stringa termina con un carattere "invisibile",
 ovvero il carattere terminatore di stringa '\0'

 in c le stringhe sono rappresentate da degli array di char.
*/

// strlen(stringa) -> restituisce la lunghezza della stringa (numero di caratteri)
// strcat(stringa1, stringa2) -> concatena nella stringa1, l'unione tra stringa1 e stringa2
// strcpy(stringa1, stringa2) -> copia la stringa2 nella stringa1
// strcmp(stringa1, stringa2) -> restituisce 0 se le 2 stringhe sono uguali, 1 se stringa2 precede alfabeticamente stringa1, -1 viceversa

int main () {
    char stringa1[32] = "Ciao mondo!";
    char stringa2[32] = "Come va??";

    printf("\n\n%d -> %s", strlen(stringa1), stringa1);

    strcat(stringa1, stringa2);
    printf("\n\n%d -> %s", strlen(stringa1), stringa1);

    if (strcmp(stringa1, stringa2) == 1) {
        printf("\n\nLa stringa '%s' precede la stringa '%s'", stringa2, stringa1);
    } else if (strcmp(stringa1, stringa2) == -1) {
        printf("\n\nLa stringa '%s' precede la stringa '%s'", stringa1, stringa2);
    } else if (strcmp(stringa1, stringa2) == 0) {
        printf("\n\nLa due stringhe: '%s' e '%s' sono uguali", stringa1, stringa2);
    }

    printf("\n\n%d -> %s", strlen(stringa1), stringa1);
    printf("\n%d -> %s", strlen(stringa2), stringa2);
    strcpy(stringa1, stringa2);
    printf("\n\n%d -> %s", strlen(stringa1), stringa1);
    printf("\n%d -> %s", strlen(stringa2), stringa2);
}