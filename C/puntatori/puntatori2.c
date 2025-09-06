#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10

int dim_array_pari;

// array statico: int array[DIM];
// array dinamico: int *array = (int*)malloc(DIM * sizeof(int));

/* random:
    #include <time.h>
    int main() {
        srand(time(NULL)); // serve sempre
        int x = rand() % 10; // genera un numero random tra 0 9
    }
*/

void popola_array_dinamicamente(int *array_dinamico) {
    srand(time(NULL));
    for (int i = 0; i < DIM; i++) {
        array_dinamico[i] = rand() % 10;
    }
}

void stampa_array(int *array_dinamico, int dim) {
    for (int i = 0; i < dim; i++) {
        printf("%d ", array_dinamico[i]);
    }
    printf("\n");
}

// funzione che ritorna un array con solo i pari
int* crea_array_pari(int *array_dinamico) {
    int *array_pari = (int*)malloc(DIM * sizeof(int));
    int contatore_pari = 0;
    for (int i = 0; i < DIM; i++) {
        if (array_dinamico[i] % 2 == 0) {
            array_pari[contatore_pari] = array_dinamico[i];
            contatore_pari++;
        }
    }
    dim_array_pari = contatore_pari;
    array_pari = (int*)realloc(array_pari, contatore_pari * sizeof(int)); // ridimensiona l'array
    return array_pari;
}

int main () {
    int *array_dinamico = (int*)malloc(DIM * sizeof(int)); // creazione array dimanico

    popola_array_dinamicamente(array_dinamico);
    stampa_array(array_dinamico, DIM);
    int *array_pari = crea_array_pari(array_dinamico);
    stampa_array(array_pari, dim_array_pari);

    free(array_pari);
    free(array_dinamico);  // libero spazio (obbligatorio)
    return 0;
}