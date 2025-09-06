#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
const int DIM = 20;

void stampa_array(int valori[]) {
    for (int i = 0; i < DIM; i++) {
        printf("%d ", valori[i]);
    }
    printf("\n");
}

void bubble_sort(int valori[]) {
    int iterazioni = 0;
    int scambi = 0;
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM - 1; j++) {
            iterazioni++;
            if (valori[j] > valori[j+1]) {
                int temp = valori[j];
                valori[j] = valori[j+1];
                valori[j+1] = temp;
                scambi++;
            }
        }
    }

    printf("iterazioni = %d; scambi = %d\n", iterazioni, scambi);
}

void bubble_sort_ottimizzato(int valori[]) {
    int iterazioni = 0;
    int scambi = 0;
    for (int i = 0; i < DIM; i++) {
        bool scambiato = false;
        for (int j = 0; j < DIM - 1; j++) {
            iterazioni++;
            if (valori[j] > valori[j+1]) {
                int temp = valori[j];
                valori[j] = valori[j+1];
                valori[j+1] = temp;
                scambiato = true;
                scambi++;
            }
        }

        if (!scambiato) {
            break;
        }
    }

    printf("iterazioni = %d; scambi = %d\n", iterazioni, scambi);
}

void bubble_sort_sentinella(int valori[]) {
    int iterazioni = 0;
    int scambi = 0;

    int ultima_posizione;
    int lunghezza = DIM;

    do {

        ultima_posizione = 0;

        for (int j = 0; j < lunghezza - 1; j++) {
            iterazioni++;
            if (valori[j] > valori[j+1]) {
                int temp = valori[j];
                valori[j] = valori[j+1];
                valori[j+1] = temp;
                
                ultima_posizione = j + 1;

                scambi++;
            }
        }

        lunghezza = ultima_posizione;

    } while (lunghezza > 1);

    printf("iterazioni = %d; scambi = %d\n", iterazioni, scambi);
}

void bubble_sort_sentinella_ottimizzato(int valori[]) {
    int iterazioni = 0;
    int scambi = 0;

    

    printf("iterazioni = %d; scambi = %d\n", iterazioni, scambi);
}

int main () {
    srand(time(NULL));
    int valori[DIM];

    for (int i = 0; i < DIM; i++) {
        valori[i] = rand() % 50;
    }

    stampa_array(valori);

    int scelta;

    do {
        printf("Scegli un metodo di ordinamento:\n0) Esci;\n1) Bubble sort;\n2) Bubble sort ottimizzato;\n3) Bubble sort sentinella;\nScelta: ");
        scanf("%d", &scelta);
        
        int array_copia[DIM];
        for (int i = 0; i < DIM; i++) {
            array_copia[i] = valori[i];
        } 

        switch (scelta) {
            case 0:
                break;
            case 1: // -> per entarre qui l'utende deve digitare 1
                bubble_sort(array_copia);
                stampa_array(array_copia);
                break; // -> ogni case termina con un break
            case 2:
                bubble_sort_ottimizzato(array_copia);
                stampa_array(array_copia);
                break;
            case 3:
                bubble_sort_sentinella(array_copia);
                stampa_array(array_copia);
                break;
            case 4:
                bubble_sort_sentinella_ottimizzato(array_copia);
                stampa_array(array_copia);
                break;
            default: // caso in cui l'utente digita un'altro numero
                printf("Scelta non valida.\n");
                break;
        }
    } while (scelta != 0);


    return 0;
}