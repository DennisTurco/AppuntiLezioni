#ifndef COMPITO_H
#define COMPITO_H
#include <iostream>
using namespace std;

class SonicLevel {
    static const int maxrighe=8;
    static const int maxcolonne=32;
    char schema[maxrighe][maxcolonne];
    int i_sonic;
    int j_sonic;
    int anelli_raccolti;
    bool gioco_fermo;

private:
    bool muro_a_destra() const;
    void raccolta_anello();
    bool gestione_spuntone();
    bool supporto_sotto() const;
    bool buca_piccola() const
    void caduta();

public:
    SonicLevel();
    ~SonicLevel();
    friend ostream& operator<< (ostream& , const SonicLevel&);
    SonicLevel& blocchi(int, int, int, int);
    SonicLevel& anello(int, int);
    void avvia(int, int);
    SonicLevel& operator+=(int);
    SonicLevel& operator*=(int);
    SonicLevel& spuntone(int, int);
};

#endif //COMPITO_H