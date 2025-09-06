#include <stdlib.h>
#include <stdio.h>

/* ESERCIZIO
Esecizio 3. Leggere 10 numeri e se il primo è pari contare quanti numeri pari 
vengono inseriti, se è dispari quanti zeri (come numeri) vengono inseriti.
*/

// es: 2,3,5,3,3,8,5,3,5,9 --> i numeri pari sono: 2 
// es: 3,3,0,3,0,8,5,0,5,9 --> i numeri nulli sono: 3

int main() {
    int n;
    int primo_n;
    int pari = 0;
    int zeri = 0;

    for (int i = 0; i < 10; i++) {
        printf("Inserisci un valore: ");
        scanf("%d", &n);

        // salvo la variabile solo per la prima iterazione (giro) del ciclo
        if (i == 0) {
            primo_n = n;
        }

        if ((primo_n % 2 == 0) && (n % 2 == 0)) { // caso pari
            pari++;
        }
        else if ((primo_n % 2 == 1) && (n == 0)) { // caso dispari
            zeri++;
        }
    }

    if (primo_n % 2 == 0) {
        printf("i numeri pari sono: %d", pari);
    } else {
        printf("i numeri nulli sono: %d", zeri);
    }
}