#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// for          --> piu' usato
// while        --> abbastanza usato
// do while     --> poco usato
// la scelta di un tipo di ciclo e' data dalla comodita'

/* ESERCIZIO
L'utente inserisce a tastiera 5 valori e il programma stampa 
quanti sono positivi, negati e nulli
*/

// 4 3 0 -1 2

int main () {
    // ################ FOR 
    int a;
    int cont_positivi = 0;
    int cont_negativi = 0;
    int cont_nulli = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a);    // inserisco un valore da tastiera
        
        // faccio il controllo qui dentro al ciclo perche' verifico PER OGNI valore 
        if (a > 0) {
            cont_positivi++; // incremento la variabile di 1
        }
        else if (a < 0) {
            cont_negativi++;
        }
        else {
            cont_nulli++;
        }
    }
    
    printf("valori positivi: %d\n", cont_positivi);
    printf("valori negativi: %d\n", cont_negativi);
    printf("valori nulli: %d\n", cont_nulli);


    // ################ WHILE 
    /*int a;
    int cont_positivi = 0;
    int cont_negativi = 0;
    int cont_nulli = 0;
    int i = 0;
    while (i < 5) {
        scanf("%d", &a);

        if (a > 0) {
            cont_positivi++;
        }
        else if (a < 0) {
            cont_negativi++;
        }
        else {
            cont_nulli++;
        }
        
        i++;
    }
    
    printf("valori positivi: %d\n", cont_positivi);
    printf("valori negativi: %d\n", cont_negativi);
    printf("valori nulli: %d\n", cont_nulli);
    */

    return 0;
}