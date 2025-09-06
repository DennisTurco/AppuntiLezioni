#include <stdlib.h>
#include <stdio.h>

/* ESERCIZIO
    Esecizio 5. Far inserire due numeri naturali, e se sono in ordine crescente far 
    stampare tutti i numeri compresi nell’intervallo tra i due, altrimenti stampare 
    il più piccolo divisore comune tra i due uno escluso, nel caso l’unico divisore 
    sia uno far stampare uno.
*/

int main() {
    int n1, n2;

    printf("Inserire primo valore: ");
    scanf("%d", &n1);
    printf("Inserire secondo valore: ");
    scanf("%d", &n2);

    if (n1 < n2) {
        for (int i = n1; i <= n2; i++) {
            printf("%d ", i);
        }
    }
    else {
        // ...



    }
}