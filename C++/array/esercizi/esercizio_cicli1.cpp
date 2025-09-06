#include <iostream>
using namespace std;

int main() {

    // ------------- ESERCIZIO 1 -------------
    // il primo ciclo viene ripetuto 5 volte
    // il secondo ciclo viene ripetuto 5 volte * 5 volte

    int val = 1;

    for (int i=0; i<5; i++) {
        for (int a=0; a<5; a++) {
            cout << "i = " << i << endl;
            cout << "a = " << a << endl;
            cout << "Valore = " << val << endl << endl;
            val++; //  => val = val + 1;
        }
    }

    cout << "----------------------------------------------------------------" << endl;
    
    // ------------- ESERCIZIO 2 -------------
    // il primo ciclo viene ripetuto 5 volte
    // il secondo ciclo viene ripetuto 5 volte

    int val2 = 0;

    for (int i=0; i<5; i++) {
        val2++;
    }

    for (int a=0; a<5; a++) {
        val2++;
    }

    cout << "Valore = " << val2 << endl << endl;


    cout << "----------------------------------------------------------------" << endl;

    // ------------- ESERCIZIO 3 -------------
    // il primo ciclo viene ripetuto 5 volte
    // il secondo ciclo viene ripetuto 5*5 volte
    // il terzo ciclo viene ripetuto 5*5*3 volte

    int val3 = 1;

    for (int i=0; i<5; i++) {
        for (int a=0; a<5; a++) {
            for (int x=0; x<3; x++) {
                cout << "i = " << i << endl;
                cout << "a = " << a << endl;
                cout << "x = " << x << endl;
                cout << "Valore = " << val3 << endl << endl;
                val3++; //  => val = val + 1;
            } 
        }
    }
}
