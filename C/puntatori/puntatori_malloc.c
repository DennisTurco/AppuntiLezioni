#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// malloc
// calloc
// realloc
// free

int dim_array_pari; // NO! solo per oggi

void stampa_array(int *array, int dim) {
    for (int i = 0; i < dim; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void popola_array(int *array, int dim) {
    srand(time(NULL));
    for (int i = 0; i < dim; i++) {
        array[i] = rand() % 10;
    }
}

// funzione che crea un nuovo array e lo ritorna
// 4 3 1 6 7
// 4 6
int* crea_array_pari(int *array, int dim) {
    int *array_pari = (int*) malloc(dim * sizeof(int));
    int cont_pari = 0;

    for (int i = 0; i < dim; i++) {
        if (array[i] % 2 == 0) {
            array_pari[cont_pari] = array[i];
            cont_pari++;
        }
    }

    dim_array_pari = cont_pari;
    array_pari = (int*) realloc(array_pari, cont_pari * sizeof(int)); // ridimensionamento
    return array_pari;
}

int main () {
    int dim = 5;
    int *array_dinamico = (int*) malloc(dim * sizeof(int));

    popola_array(array_dinamico, dim);
    stampa_array(array_dinamico, dim);

    int *pari = crea_array_pari(array_dinamico, dim);

    stampa_array(pari, dim_array_pari);

    free(array_dinamico); // obbligatorio
    free(pari); // obbligatorio
    return 0;
}