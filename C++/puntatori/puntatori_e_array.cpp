#include <iostream>
using namespace std;

void stampa_array(int n[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << n[i] << " ";
    }
}

int main() {

    int v[] = {9, 3, 2, 1, 5};
    
    int *p = v+1;
    cout << "p -> v[1]\t" << *p << endl;
    stampa_array(v, 5);
    cout << "\n----------------------------\n";

    *p = 10;
    cout << "*p = 10 <==> v[1] = 10\t" << *p << endl;
    stampa_array(v, 5);
    cout << "\n----------------------------\n";

    p = v+2;
    cout << "p -> v[2]\t" << *p << endl;
    stampa_array(v, 5);
    cout << "\n----------------------------\n";

    *p = 12;
    cout << "*p = 12 <==> v[2] = 12\t" << *p << endl;
    stampa_array(v, 5);
    cout << "\n----------------------------\n";

    return 0;
}