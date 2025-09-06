#include <stdlib.h>
#include <stdio.h>
#define DIM 5

// – qsort() → ordinamento array generico
    // Gli passiamo:
    //   - l'array
    //   - la dimensione dell'array
    //   - la dimensione del tipo dell'array
    //   - la funzione di confronto

// – bsearch() → ricerca in array ordinati
    // Gli passiamo:
    //   - l'indirizzo di memoria del valore da cercare
    //   - l'array
    //   - la dimensione dell'array
    //   - la dimensione del tipo dell'array
    //   - la funzione di confronto

void stampa(int vett[]) {
    for (int i = 0; i < DIM; i++) {
        printf("%d ", vett[i]);
    }
    printf("\n");
}

int confronta(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// in alternativa, se non vogliamo usare qsort:
void my_qsort(int vett[]) {
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM-1; j++) {
            if (vett[j] > vett[j+1]) {
                int temp = vett[j];
                vett[j] = vett[j+1];
                vett[j+1] = temp;
            }
        }
    }
}

// in alternativa, se non vogliamo usare bserach:
bool my_bserach(int vett[], int val_da_trovare) {
    for(int i = 0; i < DIM; i++) {
        if (vett[i] == val_da_trovare) {
            return true;
        }
    }
    return false;
}

int main () {

    int vett[] = {3, 1, 4, 1, 5};
    qsort(vett, DIM, sizeof(int), confronta); // ordina un array
    stampa(vett);

    int key = 4;
    int *p = (int*) bsearch(&key, vett, DIM, sizeof(int), confronta);

    if (p == NULL) {
        printf("Elemento non trovato\n");
    }
    else {
        printf("Elemento trovato: %d", *p);
    }

    return 0;
}