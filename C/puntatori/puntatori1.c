#include<stdio.h>

int main () {
    int y = 5;
    int *x = &y; // x punta all'indirizzo di memoria di y (conosce il valore di y)
    printf("%d %d", y, *x); // con *x -> mi riferisco al valore di y. con x -> mi riferisco all'indirizzo di y

    *x = 3;
    printf("\n%d %d", y, *x);

    y = 10;
    printf("\n%d %d", y, *x);

    return 0;
}