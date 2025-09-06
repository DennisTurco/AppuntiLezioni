/*Esercizio 5
Scrivere un programma che lette da tastiera le temperature T di un mese (il numero di 
giorni del mese è letto da tastiera) determini la temperatura media, 
la temperatura minima e la temperatura massima.*/

#include <stdio.h>
#include <limits.h>

int main()
{
    int temperatura;    // temperatura attuale
    int giorni;         // numero dei giorni
    float somma = 0;    // somma di tutte le temperature
    int max;            // temperatura maggiore
    int min;            // temperatura minore

    // // SOLUZIONE 1
    // max = INT_MIN;
    // min = INT_MAX;

    printf("inserisci il numero dei giorni: ");
    scanf("%d", &giorni);

    for (int i=0; i<giorni; i++) {
        printf("inserisci la temperatura: ");
        scanf("%d", &temperatura);

        // calcolo per la media
        somma = somma + temperatura;    // somma += temperatura;

        // SOLUZIONE 2
        if (i == 0) {
            max = temperatura;
            min = temperatura;
        }

        // cerco maggiore
        if (temperatura > max) {
            max = temperatura;          // aggiorno la nuova temperatura massima
        }

        // cerco minore
        if (temperatura < min) {
            min = temperatura;          // aggiorno la nuova temperatura minore
        }
    }

    printf("La temperatura maggiore e': %d\n", max);
    printf("La temperatura minore e': %d\n", min);
    printf("La temperatura media e': %f\n", somma/giorni);

    return 0;
}