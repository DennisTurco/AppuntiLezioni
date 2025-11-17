#include <iostream>
#include <memory>
using namespace std;

int main () {
    auto ptr = make_shared<int>(42);

    auto lambda = [ptr]() { // cattura shared_ptr per tenerlo vivo
        cout << *ptr << endl;
    };

    lambda();

    //////////////////////////////////////

    auto up = make_unique<int>(10);

    // per rendere il puntatore accedibile solo una volta con la lambda
    auto lambda2 = [up = move(up)]() {
        cout << *up << endl;
    };

    lambda2();
    lambda2();
    cout << *up << endl; // NON SI puo' piu' fare perche' effettuata la move con la lambda
}