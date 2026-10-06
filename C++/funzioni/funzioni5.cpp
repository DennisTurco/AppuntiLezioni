#include <iostream>
using namespace std;

int aumenta(int x) {
    x = x + 3; // 10
    cout << "Dentro aumenta: " << x << endl;
}

int main() {
    int n = 7;
    aumenta(n);
    cout << "Nel main: " << n << endl;
}


// output:
/*
Dentro aumenta: 10
Nel main: 7

*/