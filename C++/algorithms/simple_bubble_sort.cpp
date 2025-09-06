#include <iostream>
using namespace std;

int main () {
    int dim = 10;
    int numeri[dim] = {3,4,2,6,4,2,1,6,8,7};
    //int numeri[dim] = {10,9,8,7,6,5,4,3,2,1};

    // bubble sort
    for (int i = 0; i < dim; i++) {         // ciclo piu' esterno -> serve per ripetere piu' volte l'ordinamento
        for (int j = 0; j < dim-1; j++) {   // ciclo piu' interno -> rappresenta l'ordinamento vero e prorpio
            if (numeri[j] > numeri[j+1]) {
                int temp = numeri[j];
                numeri[j] = numeri[j+1];
                numeri[j+1] = temp;
            }
        }
    }

    // stampa
    for (int i = 0; i < dim; i++) {
        cout << numeri[i] << " ";
    }

    /*
        cout << endl;
        for (int i = 0; i < dim; i+=2) {
            cout << numeri[i] << " ";
        }
    */

    return 0;
}