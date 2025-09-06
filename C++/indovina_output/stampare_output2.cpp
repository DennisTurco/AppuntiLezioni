#include <iostream>
using namespace std;

int a = 10;

int g (int b) {
    return ++a + b;
}

int f (int b, int c) {
    c = g(a++);
    return c;
}

int main () {
    int c = 5;
    c = f(c++, --a);
    return 0;
}

int p = 20;

/*
    OUTPUT:
    globali -> a = 10;
    main()  -> c = 5;

    globali -> a = 9;
    f()     -> b = 5; c = 9;

    globali -> a = 10;
    g()     -> b = 9;
    globali -> a = 11;
    g()     -> b = 9;
        -> return: 20
    
    globali -> a = 11;
    f()     -> b = 5; c = 20;
        -> return: 20

    globali -> a = 11;
    main()  -> c = 20;


*/