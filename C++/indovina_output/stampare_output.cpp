#include <iostream>
using namespace std;

int a = 10; 
int b = 20; 

int g(int b) { 
    return ++a + b; 
} 

int f(int a, int b) { 
    int c; 

    c = g(++a); 
    c = c + g(b++); 

    return c; 
} 

int main() { 
    int c = 5; 

    c = f(c++,--a); 

    return 0; 
}

/*
    global:
        a = 10 
        b = 20 
    main:
        c = 5
        a = 10
        -> f(c++,--a) 
            a = 5
            b = 9
            -> g(++a)
                b = 6
                a = 9
                <- return 16 (++a + b)
            -> g(b++)
                b = 9
                a = 10
                <- return 20 (++a + b)
            <- return 36
        c = 36
        a = 11
        b = 20
*/