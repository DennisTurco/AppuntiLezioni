#include <stdio.h>

int main() {
    int voti[5];

    // inserimento voti da tastiera
    for (int i = 0; i < 5; i++) {
        printf("Inserire voto: ");
        scanf("%d", &voti[i]);
    }

    // stampa dei voti (stampa array)
    for (int i = 0; i < 5; i++) {
        printf("%d ", voti[i]);
    }

    // modifichiamo il 3^ voto
    voti[2] = 10;

    printf("\n");

    // ristampiamo
    for (int i = 0; i < 5; i++) {
        printf("%d ", voti[i]);
    }
}