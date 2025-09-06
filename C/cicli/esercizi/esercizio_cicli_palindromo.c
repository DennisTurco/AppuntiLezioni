#include <stdlib.h>
#include <stdio.h>

int main () {
    int const dim = 10;
    char parola[] = {'1', '2', '3', '4', '5', '5', '4', '3', '2', '1'};
    int controllo = 0;

    /*MODO 1*/
    // int j = dim-1;
    // for (int i = 0; i < dim/2; i++) {
    //     printf("%c -- %c\n", parola[i], parola[j]);
    //     if (parola[i] != parola[j]) {
    //         controllo = 1;
    //         break;
    //     }
    //     j--;
    // }

    /*MODO 2*/
    for (int i = 0; i< dim/2; i++) {
        printf("%c -- %c\n", parola[i], parola[dim-i-1]);
        if (parola[i] != parola[dim-i-1]) {
            controllo = 1;
            break;
        }
    }

    if (controllo == 0) {
        printf("e' palindromo");
    } else {
        printf("non e' palindromo");
    }

    return 0;
}