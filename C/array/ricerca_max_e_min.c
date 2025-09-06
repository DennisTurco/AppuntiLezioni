#include <stdio.h>
#include <stdlib.h>
#define DIM 10

int main () {
    int vett[] = {2, 3, 1, 8, 4, 3, 1, 2, 4, 6};

    // ricerca max
    int max = vett[0];
    for (int i = 0; i < DIM; i++) {
        if (vett[i] > max) {    // per trovare il min inverti il simbolo '>' con '<'
            max = vett[i];
        }
    }
    printf("il valore massimo presente nell'array e': %d", max);

    return 0;
}