#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Analizzatore di dati utente

Scrivi un programma in C che legga da una stringa simulando una riga di dati utente separata da spazi, ad esempio:
"42 1000000 3.75 John"

I dati rappresentano:
1. Età (intero)
2. Saldo conto (long)
3. Altezza (double)
4. Nome (stringa)

Esempio di output:
Età: 42
Saldo: 1000000
Altezza: 3.750000
Nome: John
*/

int main () {
    char riga[] = "42 1000000 3.75 John";
    char *ptr = riga;
    char *endptr;

    int eta = atoi(ptr);
    while (*ptr != ' ' && *ptr != '\0'){
        ptr++;
    }
    if (*ptr == ' ') {
        ptr++;
    }

    long saldo = strtol(ptr, &endptr, 10);
    ptr = endptr;

    double altezza = strtod(ptr, &endptr);
    ptr = endptr;

    char nome[32];
    strcpy(nome, ptr);

    printf("Esempio di output:\n");
    printf("Eta': %d\n", eta);
    printf("Saldo: %ld\n", saldo);
    printf("Altezza: %f\n", altezza);
    printf("Nome: %s\n", nome);

    return 0;
}