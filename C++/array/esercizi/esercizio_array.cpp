/*
    1. popola un array casuale di 10 elem
    2. ottieni la somma dei valori nelle posizioni pari all'array
    3. ottieni la media della somma precedente
    4. salva in un nuovo array i valori minori della media calcolata
*/

#include <iostream>
#include <ctime>
using namespace std;

int main () {
    const int dim = 10;
    int array[dim];

    // ############## popolamento casuale dell'array ##############
    srand(time(NULL));
    for (int i = 0; i < dim; i++) {
        int val_random = rand() % 10; // genera un valore randomico da 0 a 9
        array[i] = val_random;  // salvando il valore randomico nell'array
        cout << array[i] << " ";
    }

    // ############## somma nelle posizioni pari ##############
    float somma = 0;
    for (int i = 0; i < dim; i++) {
        if (i % 2 == 0) {   // verificando se l'indice e' pari
            somma = somma + array[i];   // aggiorno la somma
        }
    }
    cout << "\nsomma = " << somma;

    // ############## ottieni la media della somma precedente ##############
    float media = somma / (dim/2);
    cout << "\nmedia = " << media;

    // ############## salva in un nuovo array i valori minori della media calcolata ##############
    int array_media[dim];
    for (int i = 0; i < dim; i++) {
        if (array[i] < media) {
            array_media[i] = array[i]; // correggi la prima i
        }
    }

    // 0 0 268501009 0 383911784 3 -1547457914 32763 0 2    NO
    // 0 0 3 0 2 268501009 0 383911784 -1547457914 32763    SI

    // stampo nuovo array
    cout << endl;
    for (int i = 0; i < dim; i++) {
        cout << array_media[i] << " ";
    }


    return 0;
}