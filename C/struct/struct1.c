#include <stdio.h>
#include <stdlib.h>

// char, int, float, long, ecc... sono tipi di dato ATOMICI
// i tipi di dato definiti da utente non sono atomici

// tipo di dato definito da utente
struct studente{
    char nome[100];
    char cognome[100];
    int matricola;
};

int main() {
    struct studente s;

    printf("Inserisci il tuo nome: ");
    scanf("%s", s.nome);
    printf("Inserisci il tuo cognome: ");
    scanf("%s", s.cognome);
    printf("Inserisci la tua matricola: ");
    scanf("%d", &s.matricola);

    printf("Immissione avvenuta con successo!\n\n");

    printf("studente: \nnome: %s\ncognome: %s\nmatricola: %d", s.nome, s.cognome, s.matricola);

    return 0;
}