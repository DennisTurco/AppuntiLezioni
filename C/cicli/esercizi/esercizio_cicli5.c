#include <stdlib.h>
#include <stdio.h>

/* ESERCIZIO
l'utente inserisce a tastiera n valori e il programma stampa quanti sono pari.
il valore di n e' dinamico (cambia a discrezione dell'utente), in particolare 
l'immissione dei valori termina quando l'utente inserisce 0
*/

// lo facciamo solo con il while e non con il for perche' il FOR e' comodo
// per cicli di lunghezza FISSA, mentre il while e' comodo per cici 
// di lunghezza variabile.

int main () {
    // ################ WHILE 
    /*
    int a;
    int n_pari = 0;
    scanf("%d", &a);
    while(a != 0) {
        if(a % 2 == 0) {
            n_pari++;
        }
        scanf("%d", &a);
    }
    printf("valori pari: %d", n_pari);
    */

    
    // ################ DO WHILE 
    int a;
    int n_pari = 0;
    do {
        scanf("%d", &a);
        if(a % 2 == 0) {
            n_pari++;
        }
    } while(a != 0);

    printf("valori pari: %d", n_pari);
    
    return 0;
}