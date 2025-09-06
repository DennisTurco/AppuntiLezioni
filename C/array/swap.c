#include <stdio.h>
#include <time.h>

#define MAX 10

int main() {
    int v[MAX];

    srand(time(NULL));

    for (int i = 0; i < MAX; i++) {
        v[i] = rand() % 10;
    }

    for (int i = 0; i < MAX; i++) {
        printf("%d ", v[i]);
    }

    int n;
    printf("Inserisci il valore di N --> ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = MAX - 1; j > 0; j--) {
            int temp = v[j];
            v[j] = v[j - 1];
            v[j - 1] = temp;
        }
    }

    for (int i = 0; i < MAX; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
