#include <stdio.h>
#include <stdlib.h>
#define DIM 3

struct data {
    int giorno;
    int mese;
    int anno;
};

struct studente{
    char nome[100];
    char cognome[100];
    int matricola;
    struct data data_nascita;
};

int main() {
    struct studente s[DIM];

    for (int i = 0; i < DIM; i++) {
        printf("Inserisci il tuo nome: ");
        scanf("%s", s[i].nome);
        printf("Inserisci il tuo cognome: ");
        scanf("%s", s[i].cognome);
        printf("Inserisci la tua matricola: ");
        scanf("%d", &s[i].matricola);
        printf("Inserisci la tua data di nascita: ");
        scanf("%d/%d/%d", &s[i].data_nascita.giorno, &s[i].data_nascita.mese, &s[i].data_nascita.anno);
    }
    printf("Immissione avvenuta con successo!\n\n");

    for (int i = 0; i < DIM; i++) {
        printf("\nstudente %d: \n\tnome: %s\n\tcognome: %s\n\tmatricola: %d\n\tdata di nascita: %d/%d/%d", i+1, s[i].nome, s[i].cognome, s[i].matricola, s[i].data_nascita.giorno, s[i].data_nascita.mese, s[i].data_nascita.anno);
    }

    return 0;
}