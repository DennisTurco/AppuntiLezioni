#include <iostream> 
using namespace std;

int main () {
    int *p1, *p2, *p3;
    int a, b, c;

    a = 5;
    b = 7;
    c = -2;

    p2 = &c;    // p2 -> c
    p1 = &b;    // p1 -> b
    p3 = p1;    // p3 -> b

    a = ((*p2) + (*p1)) / 3;    // a = 1
    *p1 = a * (*p2) - 2*(*p3);  // b = -16
    *p2 = a + (*p1) - (*p2);    // c = -13
    
    p3 = p2;        // p3 -> c
    p2 = &(*p1);    // p2 -> b
    p1 = &a;        // p1 -> a

    *p1 = ((*p2) * 4) / (*p3);      // a = 4
    *p2 = (*p1) + (*p2) - 3*(*p3);  // b = 27
    *p3 = ((*p1) * (*p2)) / 5;      // c = 21

    cout << a << endl;      // 4
    cout << b << endl;      // 27
    cout << c << endl;      // 21
    cout << *p1 << endl;    // 4
    cout << *p2 << endl;    // 27
    cout << *p3 << endl;    // 21
    cout << p1 << endl;     // indirizzo1
    cout << p2 << endl;     // indirizzo2
    cout << p3 << endl;     // indirizzo3
}