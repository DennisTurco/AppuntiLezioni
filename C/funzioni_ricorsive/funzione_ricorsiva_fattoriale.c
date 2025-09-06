#include <stdio.h>
#include <stdlib.h>

/*
    0! -> 1
    1! -> 1
    2! -> 2 * 1 = 2
    3! -> 3 * 2 * 1 = 6
    4! -> 4 * 3 * 2 * 1 = 24
*/

int fattoriale_semplice(int n) {
    int count = 1;
    for (int i=1; i<=n; i++) {
        count *= i;
    } 
    return count;
}

// ogni funzione ricorsiva per essere tale deve avere ALMENO un caso base ed un passo induttivo
long fattoriale(int val) {
    // caso base (caso d'uscita)
    if (val == 0 || val == 1) return 1;

    // passo induttivo (ricorsione vera e propia)
    return val * fattoriale(val-1);
}

/*
    funzione 1 -> val = 4 -> return 4 * fattoriale(3)
        funzione 2 -> val = 3 -> return 3 * fattoriale(2)
            funzione 3 -> val = 2 -> return 2 * fattoriale(1)
                funzione 4 -> val = 1 -> return 1
                Termina la funzione 4 restituendo 1
            Termina la funzione 3 restituendo 2
        Termina la funzione 2 restituendo 6
    Termina la funzione 1 restituendo 24
*/

int main () {
    const int val = 5;

    printf("%d! = %d\n", val, fattoriale(val));
    printf("%d! = %d", val, fattoriale_semplice(val));

    return 0;
}