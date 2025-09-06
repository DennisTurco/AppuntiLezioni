#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void stampa(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void partitionArray(int arr[], int size, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    int smaller = 0;

    // Sposta l'elemento pivot alla fine del vettore
    swap(&arr[pivotIndex], &arr[size - 1]); // scambio
    
    // queste stampe sono inutili, servono solo per avere una maggiore comprensione
    printf("%d <-> %d\t", arr[pivotIndex], arr[size - 1]);
    stampa(arr, size);

    // Scansiona il vettore e sposta gli elementi minori a sinistra del pivot
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] <= pivotValue) {
            swap(&arr[i], &arr[smaller]);   // scambio
            smaller++;
            
            // queste stampe sono inutili, servono solo per avere una maggiore comprensione
            printf("%d <-> %d\t", arr[i], arr[smaller]);    
            stampa(arr, size);
        }
    }

    // Sposta l'elemento pivot nella sua posizione corretta
    swap(&arr[smaller], &arr[size - 1]);    // scambio
}

int main() {

    int N = 5;
    int arr[] = {7, 25, 11, 4, 15};

    printf("Vettore generato:\n");
    stampa(arr, N);

    int randomIndex = 2;

    partitionArray(arr, N, randomIndex);

    printf("Vettore partizionato:\n");
    stampa(arr, N);

    return 0;
}
