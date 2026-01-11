#include <stdio.h>

int main () {
    int n;
    int numeri[100];

    do {
        printf("Inserisci un numero da 1 a 99: ");
        scanf("%d", &n);
    } while (n >= 100 || n <= 0);

    int pos = 0;
    for (int i = 1; i <= n; i++) { // trovare il numero -> i = numero divisore (forse)
        if (n % i == 0) {
            numeri[pos] = i;
            pos++;
        }
    }

    for (int i = 0; i < pos; i++) {
        printf("%d ", numeri[i]);
    }
}
