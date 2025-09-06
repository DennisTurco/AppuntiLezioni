#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    int *ptr_a, *ptr_b, *ptr_c, *ptr_d;

    a = 10;
    b = -5;
    c = 3;
    d = 7;

    ptr_a = &a;     // ptr_a -> a
    ptr_b = &b;     // ptr_b -> b
    ptr_c = &c;     // ptr_c -> c
    ptr_d = &d;     // ptr_d -> d

    *ptr_a = (*ptr_b) + (*ptr_c);       // a = -2
    *ptr_b = (*ptr_a) * 2 - (*ptr_d);   // b = -11
    *ptr_c = (*ptr_a) - (*ptr_b);       // c = 9
    *ptr_d = (*ptr_c) + (*ptr_b);       // d = -2

    ptr_a = ptr_b;      // ptr_a -> b
    ptr_b = &c;         // ptr_b -> c    
    ptr_c = &(*ptr_d);  // ptr_c -> d
    ptr_d = &(*ptr_a);  // ptr_d -> b

    *ptr_a = (*ptr_b) * 3;          // b = 27
    *ptr_b = (*ptr_d) - (*ptr_c);   // c = 29
    *ptr_c = (*ptr_a) - (*ptr_d);   // d = 0
    *ptr_d = (*ptr_a) + (*ptr_c);   // b = 27

    cout << "a: " << a << endl; // -2
    cout << "b: " << b << endl; // 27
    cout << "c: " << c << endl; // 29
    cout << "d: " << d << endl; // 0

    cout << "Pointer to a: " << ptr_a << endl;  // ptr_a -> b
    cout << "Pointer to b: " << ptr_b << endl;  // ptr_b -> c
    cout << "Pointer to c: " << ptr_c << endl;  // ptr_c -> d
    cout << "Pointer to d: " << ptr_d << endl;  // ptr_d -> b

    return 0;
}