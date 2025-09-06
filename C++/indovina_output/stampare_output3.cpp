#include <iostream> 
using namespace std;

int a = 5;
int b = 7;

int f (int x, int y, int z) {
    int b = 50;
    b = z - a;
    return b + x;
}

int c = 10;

int g(int x, int y, int z) {
    int w;
    x = f(x+y, c++, z-y);
    w = f(++a, x, x);
    return w;
}

int main () {
    int c = 20;
    c = g(c+2, c-2, 30);    
    return 0;
}

int d = 100;

/*
    OUTPUT:
        global  -> a=5; b=7; c=10;
        main()  -> c=20;

        global  -> a=5; b=7; c=10;
        g()     -> x=22; y=18; z=30;

        global  -> a=5; b=7;
        f()     -> x=40; y=10; z=12;

        global  -> a=5; b=7;
        f()     -> x=40; y=10; z=12; b=50;

        global  -> a=5; b=7;
        f()     -> x=40; y=10; z=12; b=7;
            -> return 7+40 = 47

        global  -> a=5; b=7; c=11;
        g()     -> x=47; y=18; z=30;

        global  -> a=6; b=7;
        f()     -> x=6; y=47; z=47;

        global  -> a=6; b=7;
        f()     -> x=6; y=47; z=47; b=50;

        global  -> a=6; b=7;
        f()     -> x=6; y=47; z=47; b=41;
            -> return 47

        global  -> a=6; b=7; c=11;
        g()     -> x=47; y=18; z=30; w=47;
            -> return 47
        
        global  -> a=6; b=7; c=11;
        main()  -> c = 47;
            -> return 0
*/