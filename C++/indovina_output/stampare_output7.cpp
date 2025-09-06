#include <iostream>
using namespace std;

int main() {
    // ESERCIZIO 1
    char s[] = "Pippicalzelunghe";
    char *p = s;        // p -> s[0], *p = 'P'
    *p = *(s+4);        // p -> s[4]
    cout << *p << endl; // 'i'

    // ESERCIZIO 2
    int v[] = {0, 1, 2, 3, 4};
    int *p2 = v+1;          // p2 -> v[1]
    *(p2+1) = *(v+2) + 1;   // v[2] = 3
    cout << *(p2+1) << endl;// 3
    
    // ESERCIZIO 3
    float x = 2.0, y = 3.0;
    float *p3 = &y;     // p3 -> y
    y = (*p3) * (x);    // y = 6
    cout << y << endl;  // 6

    return 0;
}