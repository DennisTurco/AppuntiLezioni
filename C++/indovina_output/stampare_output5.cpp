#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    int *ptr1, *ptr2, *ptr3;

    x = 10;
    y = -3;
    z = 6;

    ptr1 = &x;  // ptr1 -> x
    ptr2 = &y;  // ptr2 -> y
    ptr3 = &z;  // ptr3 -> z

    *ptr1 = (*ptr2) + (*ptr3);      // x = 3
    *ptr2 = (*ptr1) * 2 - (*ptr3);  // y = 0
    *ptr3 = (*ptr1) - (*ptr2);      // z = 3

    ptr3 = ptr1;        // ptr3 -> x
    ptr1 = &y;          // ptr1 -> y
    ptr2 = &(*ptr3);    // ptr2 -> x    

    *ptr1 = (*ptr3) * 2;        // y = 6 
    *ptr2 = (*ptr1) + (*ptr3);  // x = 9
    *ptr3 = (*ptr1) - (*ptr2);  // x = -3

    cout << x << endl;      // -3 
    cout << y << endl;      // 6
    cout << z << endl;      // 3
    cout << *ptr1 << endl;  // 6
    cout << *ptr2 << endl;  // -3
    cout << *ptr3 << endl;  // -3

    cout << ptr1 << endl;   // indirizzo di y
    cout << ptr2 << endl;   // indirizzo di x
    cout << ptr3 << endl;   // indirizzo di x  

    return 0;
}