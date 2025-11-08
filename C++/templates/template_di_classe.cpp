#include <iostream>
using namespace std;

template <typename T = int> // = int significa che di default se non specificato il tipo sara' int
class Scatola {
    private:
        T contenuto;
    public:
        Scatola(T c) : contenuto(c) {}
        T get() { return contenuto; }

        template <typename U>
        void stampa(U b) {
            cout << b;
        }
};

int main () {
    Scatola<int> s1(1234);
    Scatola<string> s2("Ciao");
    Scatola<> s3(45);

    cout << s1.get() << endl;
    cout << s2.get() << endl;
    cout << s3.get() << endl;
}