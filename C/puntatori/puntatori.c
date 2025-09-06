#include <stdio.h>

void cambia_valore_normale(int p) {
    p = 999;
}

void cambia_valore_con_puntatore(int *p) {
    *p = 999;
}

int main () {
    int y = 5;
    int *x = &y; // x punta all'indirizzo di memoria di y (conosce il valore di y)

    printf("y = %d\n", y);
    printf("y = %d\n", *x);
    printf("&y = %p\n", &y);
    printf("&y = %p\n", x);

    *x += 5;
    printf("y = %d\n", y);

    cambia_valore_normale(y);
    printf("%d\n", y);

    cambia_valore_con_puntatore(&y);
    printf("%d\n", y);
}