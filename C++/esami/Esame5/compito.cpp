#include "compito.h"
using namespace std;

SonicLevel::SonicLevel() {
    for( int j=0; j < maxcolonne;j++ ) {
        schema[0][j]='=';
    }
    for (int i=1; i <maxrighe; i++ ) {
        for( int j=0;j < maxcolonne; j++ ) {
            schema[i][j]=' ';
        }
    }
    i_sonic=-1;
    j_sonic=-1;
    gioco_fermo=true;
}

SonicLevel::~SonicLevel() {}

ostream& operator<<(ostream& os, const SonicLevel &s){
    if(s.gioco_fermo){
        os << "(GIOCO FERMO)" << endl;
        return os;
    }
    os << "Anelli:" << s.anelli_raccolti << endl;
    for (int i = SonicLevel::maxrighe-1; i >= 0; i--){
        os << i;
        for(int j = 0; j < SonicLevel:: maxcolonne; j++){
            if(i == s.i_sonic && j == s.j_sonic)
                os << 'S';
            else
                os << s.schema[i][j];
        }
        os << endl;
    }
    os << ' ';
    for(int j=0; j < SonicLevel::maxcolonne; j++)
        os << j % 10;
    os << endl;

    return os;
}
SonicLevel& SonicLevel::blocchi(int i, int j, int nr, int nc){
    if(!gioco_fermo) return *this;
    if(i < 0 || i + nr >= maxrighe || j < 0 || j + nc >= maxcolonne )
        return *this;
    for (int _i = i; _i < i+nr; _i++){
        for(int _j = j; _j < j+nc; _j++){
            schema[_i][_j] = '=';
        }
    }
    return *this;
}
SonicLevel& SonicLevel::anello(int i, int j){
    if(!gioco_fermo) return *this;
    if(i < 0 || i >= maxrighe || j < 0 || j >= maxcolonne)
        return *this;
    if (schema[i][j] == ' ')
        schema[i][j] = 'o';
    return *this;
}
void SonicLevel::avvia(int _i_sonic, int _j_sonic){
    if(_i_sonic <= 0 || _i_sonic >= maxrighe)
        return;
    if(_j_sonic < 0 || _j_sonic >= maxcolonne-1)
        return;
    if(schema[_i_sonic][_j_sonic] != ' ' || schema[_i_sonic-1][_j_sonic] != '=')
        return;
    i_sonic = _i_sonic;
    j_sonic = _j_sonic;
    anelli_raccolti = 0;
    gioco_fermo = false;
}

SonicLevel& SonicLevel::operator+=(int n) {
    if(gioco_fermo || n <= 0) return *this;
    
    for(int i = 0; i < n; i++) {
        if (gioco_fermo) break;

        bool corsa = (i > 10);

        if (muro_a_destra()) break;

        // avanzamento a dx
        j_sonic++;

        raccolta_anello();

        if (getstione_spuntone()) break;

        // controllo vincita
        if (j_sonic == maxcolonne - 1) {
            gioco_fermo = true;
            break;
        }

        // caduta normale
        if (!supporto_sotto() && !corsa) {
            caduta();
        }

        // caduta su buca non piccola
        if (corsa && !supporto_sotto() && !buca_piccola()) {
            caduta();
        }
    }

    return *this;
}

bool SonicLevel::muro_a_destra() const {
    int j2 = j_sonic + 1;
    if (j2 >= maxcolonne) return true;
    char cella = schema[i_sonic][j2]; // cella a dx di sonic
    return (cella == '=' || cella == '^')
}

void SonicLevel::raccolta_anello() {
    if (schema[i_sonic][j_sonic] == 'o') {
        anelli_raccolti++;
        schema[i_sonic][j_sonic] = ' ';
    }
}

bool SonicLevel::gestione_spuntone() {
    if (schema[i_sonic][j_sonic] != '^') return false;

    if (anelli_raccolti > 0) { // caso invulnerabilita'
        anelli_raccolti = 0;
        return false;
    }
    else {
        gioco_fermo = true;
        return true;
    }
}

bool SonicLevel::supporto_sotto() const {
    char cella = schema[i_sonic - 1][j_sonic]; // cella sotto a sonic
    return (cella == '=' || (cella == '^' && anelli_raccolti > 0))
}

bool SonicLevel::buca_piccola() const {
    int j2 = j_sonic + 1;
    if (j2 >= maxcolonne || i_sonic == 0) return false;
    char c = schema[i_sonic - 1][j2];
    return (c == '=');
}

//FUNZIONI SECONDA PARTE
SonicLevel& SonicLevel::spuntone(int i, int j){
    if(!gioco_fermo) return *this;
    if(i < 0 || i >= maxrighe)
        return *this;
    if(j < 0 || j >= maxcolonne)
        return *this;
    if(schema[i][j] != ' ' && schema[i][j] != '=')
        return *this;
    schema[i][j] = '^';

    return *this;
}

SonicLevel& SonicLevel::operator*=(int n) {
    if (gioco_fermo || n <= 0) return *this;

    bool invulnerabile = false;

    // fase ascendente
    for (int k = 0; k < n && gioco_fermo == false; k++) {
        if (i_sonic >= maxrighe - 1) break; // limite superiore
        if (schema[i_sonic + 1][j_sonic + 1] == '=' || (schema[i_sonic + 1][j_sonic + 1] == '^' && !invulnerabile))
            break; // ostacolo, fermo in orizzontale
        i_sonic++;
        j_sonic++;
        raccogli();
        if (gestisci_spuntone()) return *this;
    }

    // fase discendente
    while (!supporto_sotto() && !gioco_fermo) {
        i_sonic--;
        j_sonic++;
        raccogli();
        if (gestisci_spuntone()) return *this;
        if (j_sonic >= maxcolonne - 1) break; // fine livello
    }

    // eventuale movimento orizzontale finale
    while (j_sonic < maxcolonne - 1 && !supporto_sotto() && !gioco_fermo) {
        j_sonic++;
        raccogli();
        if (gestisci_spuntone()) return *this;
    }

    // Se Sonic raggiunge l’ultima colonna, il gioco si ferma
    if (j_sonic >= maxcolonne - 1)
        gioco_fermo = true;

    return *this;
}

