#include <iostream>
using namespace std;

int main () {

    srand ((unsigned) time (NULL));
    
    int v;

    // Genera numeri casuali qualsiasi
    for (int i=0; i<10; i++) {
        v = rand();
        cout << v << " ";
    }

    cout << endl;

    // Genera numeri casuali da 1 a 5
    for (int i=0; i<10; i++) {
        v = rand() % 5 + 1;
        cout << v << " ";
    }
    
    cout << endl;

    // Genera numeri casuali da 10 a 20
    for (int i=0; i<10; i++) {
        v = rand() % 10 + 10;
        cout << v << " ";
    }
    
    cout << endl;

    return 0;
}