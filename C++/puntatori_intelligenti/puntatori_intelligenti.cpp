#include <iostream>
#include <memory>
using namespace std;

// un puntatore intelligente si differisce da un puntatore classico perchè gestisce autonomamente la
// distruzione (delete) per liberare risorse

int main () {
    unique_ptr<int> ptr = make_unique<int>(42);
    cout << *ptr << endl;

    // unique_ptr<int> ptr_copy = ptr; NON si puo' fare perche' e' unico e quindi non copiabile

    unique_ptr<int> new_ptr = move(ptr); // trasferiamo la proprieta' da ptr a new_ptr
    // cout << *ptr << endl; questo NON si puo' piu' fare perche' ptr non ha piu' la proprieta' del valore
    cout << *new_ptr << endl;

    // se si vuole avere una proprieta' condivisa e non univoca
    shared_ptr<int> shared_ptr = make_shared<int>(10);
    std::shared_ptr<int> shared_ptr2 = shared_ptr; // condivizione di proprieta'

    cout << "p1: " << *shared_ptr << ", p2: " << *shared_ptr2 << endl;

    return 0;
}