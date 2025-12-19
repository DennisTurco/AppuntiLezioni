#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>
using namespace std;

class SpaceAsteroids {
    const static int max_altezza = 7;
    const static int max_larghezza = 9;
    const static int min_altezza = 3;
    const static int min_larghezza = 3;
    const static int energia_default = 5;

    static int record;
    int punteggio;

    const int altezza;
    const int larghezza;
    const unsigned int energia_massima;

    int posizione_astronave;

    int schermo[max_altezza + 1][max_larghezza];

    int energia_rimanente;
    bool spostamento_permesso;
    bool laser_permesso;

    void avanza_asteroidi();
    void carica_partita();
    void aumenta_punteggio();

public:
    SpaceAsteroids(int altezza, int larghezza, int energia);
    bool colloca_asteroide(int col);
    void avanza();
    friend ostream &operator<<(ostream &os, const SpaceAsteroids &a);
    void operator<<=(int n);
    void operator>>=(int n);
    void operator>>=(int n);
    SpaceAsteroids &operator|=(int n);
};

#endif  //COMPITO_H