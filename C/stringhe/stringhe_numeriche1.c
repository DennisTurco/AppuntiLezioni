#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// atoi
// atol
// atof

// strtol
// strtoul
// strtod

int main () {

    // prima parte
    // atoi
    char valore_stringa_int[] = "123";
    int valore = atoi(valore_stringa_int);
    printf("Valore: %d\n", valore);

    // atol
    char valore_stringa_long[] = "123456789";
    long valore2 = atol(valore_stringa_long);
    printf("Valore: %ld\n", valore2);

    // atof
    char valore_stringa_double[] = "3.14";
    double valore3 = atof(valore_stringa_double);
    printf("Valore: %f\n", valore3);

    // seconda parte
    // strtol
    char str1[] = "12345abc";
    char *endptr1;
    long num1 = strtol(str1, &endptr1, 10); // base 10
    printf("Valore (strtol): %ld, resto: %s\n", num1, endptr1);

    // strtoul
    char str2[] = "98765xyz";
    char *endptr2;
    unsigned long num2 = strtoul(str2, &endptr2, 10); // base 10
    printf("Valore (strtoul): %lu, resto: %s\n", num2, endptr2);

    // strtod
    char str3[] = "3.14159pi";
    char *endptr3;
    double num3 = strtod(str3, &endptr3);
    printf("Valore (strtod): %f, resto: %s\n", num3, endptr3);

    return 0;
}



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

/*
// Riga di dati utente
    char riga[] = "42 1000000 3.75 John";

    // Puntatori per catturare il resto della stringa
    char *ptr = riga; // ptr punta all'inizio della stringa. Possiamo usare ptr per scorrere la stringa senza modificare l'array originale.
    char *endptr;

    // 1. Età (intero) con atoi
    int eta = atoi(ptr); // legge la prima parte numerica, ma non ci dice dove finisce il numero, quindi dobbiamo spostare il puntatore al prossimo numero.

    // Spostiamo il puntatore al primo spazio
    while (*ptr != ' ' && *ptr != '\0') ptr++; // scorre la stringa finché non trova uno spazio (o fine stringa)
    if (*ptr == ' ') ptr++; // salta lo spazio, così ptr punta all'inizio del numero successivo.

    // 2. Saldo conto (long) con strtol
    long saldo = strtol(ptr, &endptr, 10); // endptr è un puntatore che diventa la posizione del primo carattere non numerico dopo il numero.
    ptr = endptr;

    // 3. Altezza (double) con strtod
    double altezza = strtod(ptr, &endptr);
    ptr = endptr;

    // 4. Nome (stringa rimanente)
    char nome[50];
    strcpy(nome, ptr);

    // Stampa dei risultati
    printf("Età: %d\n", eta);
    printf("Saldo: %ld\n", saldo);
    printf("Altezza: %f\n", altezza);
    printf("Nome: %s\n", nome);

    return 0;
*/