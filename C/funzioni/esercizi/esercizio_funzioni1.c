/*
Creare un menu di programma per mostrare all'utente le azioni:

0. uscita
1. Inserisci manualmente i dati nell'array
2. Inserisci dei dati casuali nell'array
3. Stampa l'array
4. Stampa la somma dell'array
5. Stampa la media dell'array

Il programma attende l'input dell'utente ed esegue la relativa azione.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10

void popolamento_array(int array[], int dim) {
    for (int i = 0; i < dim; i++) {
        printf("inserire valore %d: ", i);
        scanf("%d", &array[i]);
    }
}

void popolamento_casuale_array(int array[], int dim, int min, int max) {
    for (int i = 0; i < dim; i++) {
        array[i] = min + rand() % (max - min + 1);
    }
}   

void stampa_array(int array[], int dim) {
    for (int i = 0; i < dim; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int somma_array(int array[], int dim) {
    int somma = 0;
    for (int i = 0; i < dim; i++) {
        somma += array[i];
    }
    return somma;
}

float media_array(int somma, int dim) {
    return somma / dim;
}

int main () {

    int array[DIM];
    int operazione;
    int somma;

    do {
        printf("0. uscita\n1. Inserisci manualmente i dati nell'array\n2. Inserisci dei dati casuali nell'array\n3. Stampa l'array\n4. Stampa la somma dell'array\n5. Stampa la media dell'array\ninserire l'operazione da eseguire: ");
        scanf("%d", &operazione);

        switch (operazione){
            case 0:
                break;
            case 1:
                popolamento_array(array, DIM);
                break;
            case 2:
                popolamento_casuale_array(array, DIM, 0, 20);
                break;
            case 3:
                stampa_array(array, DIM);
                break;
            case 4:
                somma = somma_array(array, DIM);
                printf("somma = %d", somma);
                break;
            case 5:
                printf("media = %d", media_array(somma, DIM));
                break;
            default:
                printf("operazione non valida");
                break;
        }

        printf("\n");

    } while (operazione != 0);

    return 0;
}