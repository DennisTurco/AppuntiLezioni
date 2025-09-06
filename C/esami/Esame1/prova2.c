#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PERCORSO "../parole.txt"
int dim = 0;

struct parole {
    char parola1[100];
    char parola2[100];
};

// ritorna 0 -> se non ci sono parole palindrome
// ritorna 1 -> se solo una delle 2 è palindroma
// ritorna 2 -> se sono tutte e due palindrome
// PUNTO 2
int check_palindromi(struct parole par) {
    return palindromo(par.parola1) + palindromo(par.parola2);
}

// n a t a n
// a n n a
// parola[0] == parola[3]
// parola[1] == parola[2]
// parola[...] == parola[...]
// parola[i] == parola[strlen(parola)-1-i]

// ritorna 0 se non è palindroma, 1 altrimenti
int palindromo(char parola[]) {
    for (int i = 0; i < strlen(parola)/2; i++) {
        // caso in cui mi accorgo che non è palindroma
        if (parola[i] != parola[strlen(parola)-1-i]) {
            return 0;
        }
    }

    // se arrivo qui sono certo che è palindromo
    return 1;
}

/* CON RICORSIONE
    // ritorna 0 se non è palindroma, 1 altrimenti (versione ricorsiva)
    int palindromo(char parola[], int inizio, int fine) {
        // Caso base: se la stringa ha lunghezza 0 o 1, è palindroma
        if (inizio >= fine) {
            return 1;
        }
        // Caso in cui i caratteri non corrispondono, non è palindroma
        if (parola[inizio] != parola[fine]) {
            return 0;
        }
        // Chiamata ricorsiva per verificare la parte interna della stringa
        return palindromo(parola, inizio + 1, fine - 1);
    }

    // Funzione per verificare le due parole nella struct (senza ciclo)
    int check_palindromi(struct parole par) {
        return palindromo(par.parola1, 0, strlen(par.parola1) - 1) +
            palindromo(par.parola2, 0, strlen(par.parola2) - 1);
    }
*/

// senatrice e cestinare -> anagrammi
// soluzione -> ordiniamo le parole -> aceeinrst e aceeinrst
// ritorna 0 se non è un anagramma, 1 altrimenti
int check_anagrammi(struct parole par) {

    // se le 2 poarole hanno dimensioni diverse allora non serve che faccio nulla, perchè so già la risposta
    if (strlen(par.parola1) != strlen(par.parola2)) {
        return 0;
    }

    char parola1[strlen(par.parola1)];
    char parola2[strlen(par.parola2)];
    strcpy(parola1, par.parola1);
    strcpy(parola2, par.parola2);

    ordina_parola(parola1);
    ordina_parola(parola2);

    for (int i = 0; i < strlen(parola1); i++) {
        if (parola1[i] != parola2[i]) {
            return 0;
        }
    }

    // se arrivo qui sono certo che è un anagramma
    return 1;
}

// ordinamento bubble sort
void ordina_parola(char parola[]) {
    for (int i = 0; i < strlen(parola); i++) {
        for (int j = 0; j < strlen(parola)-1; j++) {
            if (parola[j] > parola[j+1]) {
                char temp = parola[j];
                parola[j] = parola[j+1];
                parola[j+1] = temp;
            }
        }
    }
}



// PUNTO 1
struct parole* leggi_da_file() {
    // size mi rappresenta la dimensione massima attuale dell'array
    // la i invece mi rappresenta il numero di elementi attualmente inseriti
    int size = 5;

    // non conoscendo la dimensione del file gli asseniamo una dimensione iniziale di 5 e poi nel caso lo ingrandiamo
    struct parole *par = (struct parole*) malloc(size * sizeof(struct parole));
    FILE *file = fopen(PERCORSO, "r");

    if (file == NULL) {
        printf("Errore: file inesistente!");
        exit(-1);
    }

    int i = 0;
    while (!feof(file)) {
        if (i == size) {
            size += 5;
            par = (struct parole*)realloc(par, size * sizeof(struct parole));
        }

        fscanf(file, "%s %s\n", par[i].parola1, par[i].parola2);
        i++;
    }
    dim = i;

    fclose(file);
    return par;
}

int main () {

    struct parole *par = leggi_da_file();

    for (int i = 0; i < dim; i++) {
        int n_palindromi = check_palindromi(par[i]);
        int n_anagrammi = check_anagrammi(par[i]);
        printf("%s %s -> palindromi = %d -> anagrammi = %d\n", par[i].parola1, par[i].parola2, n_palindromi, n_anagrammi);
    }

    free(par);
    return 0;
}