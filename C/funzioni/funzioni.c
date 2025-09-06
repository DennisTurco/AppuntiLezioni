#include <stdlib.h>
#include <stdio.h>

#define DIM 10

// tutte le funzioni che aggiungi vanno messe prima del main

// le funzioni servono a:
// - fare un calcolo e ripeterlo molte volte;
// - semplificare la leggibilita' generale grazie ad una maggiore organizzazione in blocchi separati


// una funzione ha il tipo di ritorno, il nome, e nelle parentesi tonde la lista degli argomenti
// tipo di ritorno -> void
// nome -> funzione_void
// lista degli argomenti -> ()
void funzione_void() { }

// tipo di ritorno -> int
// nome -> funzione_int
// lista degli argomenti -> ()
int funzione_int() { }

// tipo di ritorno -> float
// nome -> funzione_float
// lista degli argomenti -> ()
float funzione_float() { }

// tipo di ritorno -> char
// nome -> funzione_char
// lista degli argomenti -> ()
char funzione_char() { }

void popola_array(int array[]) {
    for (int i = 0; i < DIM; i++) {
        printf("Inserire un valore: ");
        scanf("%d", &array[i]);
    }
}

float calcola_media(int arr[]) {
    float media;
    float somma = 0;
    for (int i = 0; i < DIM; i++) {
        somma += arr[i];
    }
    media = somma / DIM;

    return media; // ritorno il valore della variabile media al chiamante
}

void stampa_array(int arr[]) {
    for (int i = 0; i < DIM; i++) {
        printf("%d ", arr[i]);
    }
}

void scambia_valore_in_array(int arr[], int nuovo_valore)  {
    for (int i = 0; i < DIM; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] = nuovo_valore;
        }
    }
}

// funzione main
int main () {
    int arr[DIM];

    // popolamento array
    // per usare una funzione occorre chiamarla attraverso una chiamata di funzione
    popola_array(arr);

    // calcolo media
    float med = calcola_media(arr); // catturo il valore di ritorno della funzione e lo assegno alla variabile med
    printf("\nmedia = %f\n", med);

    // stampo array
    stampa_array(arr);

    // modifico tutti i valori pari sostituendoli con x
    scambia_valore_in_array(arr, 99);

    // stampo array
    printf("\n");
    stampa_array(arr);
}