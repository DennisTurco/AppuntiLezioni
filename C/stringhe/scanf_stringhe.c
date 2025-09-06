#include <stdio.h>

int main() {
    char string1[100];
    char string2[100];

    printf("Inserisci la prima stringa: ");
    scanf(" %[^\n]s", string1); // Legge la prima stringa, includendo spazi

    printf("Inserisci la seconda stringa: ");
    scanf(" %[^\n]s", string2); // Legge la seconda stringa, includendo spazi

    printf("Hai inserito:\n");
    printf("Prima stringa: %s\n", string1);
    printf("Seconda stringa: %s\n", string2);

    return 0;
}