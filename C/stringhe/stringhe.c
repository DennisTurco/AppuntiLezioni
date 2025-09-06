#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// strchr
// strstr

int main () {

    char *testo = "programmazione C e' bella";
    char *sub = strstr(testo, "C");

    if (sub != NULL) {
        printf("Sottostringa: %s", sub);
    } else {
        printf("Sottostringa non presente");
    }

    return 0;
}