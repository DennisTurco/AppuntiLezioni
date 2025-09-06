#include <iostream>
using namespace std;

// la funzione int restituisce un valore di tipo intero
int myFunction1(int x) {
    x = x + 5; // x += 5;
    return x;
}

// la funzione void non restituisce nulla
void myFunction2(int x) {
    x = x + 5;
    // non posso scrivere "return x;" perche' non restituisce nulla
}

int main() {

    int val1 = myFunction1(3);
    cout << "myFunction1: " << val1;
    
    // questo non si piu' fare perche' la funzione myFunction2 non restituisce nulla  
    // int val2 = myFunction2(3);
    // cout << "myFunction2: " << myFunction2(3);  
    
    cout << endl;
    
    return 0;
}