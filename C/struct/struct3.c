#include <stdio.h>
#include <stdlib.h>

/*
typedef struct anno_nascita {
    int anno;
    int mese;
    int giorno;
}anno_nascita;

typedef struct persona {
    struct anno_nascita eta;
    float altezza;
}persona;
struct persona p1;
p1.eta.anno;
*/

// nuovo tipo di dato, definito da utente che contiene tute queste informazioni
typedef struct persona {
    int eta;
    float altezza;
}persona;

int main () {
    // PARTE 1 -----------------------
    /*
    struct persona p1;

    printf("Inserire eta': ");
    scanf("%d", &p1.eta);

    printf("Inserire altezza: ");
    scanf("%f", &p1.altezza);

    printf("\n\n---------------------------------\n");

    printf("eta: %d, altezza: %f", p1.eta, p1.altezza);
    */
    // -----------------------

    // PARTE 2 -----------------------
    int dim = 3;
    struct persona p1[dim];

    for (int i = 0; i < dim; i++) {
        printf("\nInserire persona %d:\n", i+1);
        printf("Inserire eta': ");
        scanf("%d", &p1[i].eta);

        printf("Inserire altezza: ");
        scanf("%f", &p1[i].altezza);
    }

    for (int i = 0; i < dim; i++) {
        printf("\neta: %d, altezza: %f", p1[i].eta, p1[i].altezza);
    }

    // -----------------------
}