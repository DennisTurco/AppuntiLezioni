#ifndef BATTAGLIA_NAVALE_H
#define BATTAGLIA_NAVALE_H

#include <iostream>
#include <ctime>

#define DIM 10

using namespace std;

void reset_griglia(int griglia[DIM][DIM]);
int somma_totale(int griglia[DIM][DIM]);
void stampa_matrice(int griglia[DIM][DIM]);
bool nave_affondata(int griglia[DIM][DIM], int nave);
void genera_griglia(int griglia[DIM][DIM]);


#endif // BATTAGLIA_NAVALE_H