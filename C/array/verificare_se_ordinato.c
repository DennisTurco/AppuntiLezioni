#include <stdio.h>

int main () {
    //int numeri[] = {4, 2, 3, 2, 6};
    //int numeri[] = {1, 2, 3, 7, 9};
    int numeri[] = {1, 2, 10, 7, 9};

    bool ordinato = true;
    for (int i = 0; i < 5-1; i++) {
        if (numeri[i] > numeri[i+1]) {
            ordinato = false;
        }
    }

    if (ordinato == true) {
        printf("I numeri sono ordinati nel vettore");
    }
    else {
        printf("I numeri NON sono ordinati nel vettore");
    }
}