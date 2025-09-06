#include<iostream>
using namespace std;

//funzione stampa
void stampa(){
    cout<<"Ho Stampato";
}

//funzione somma
int somma(int n, int m){ //in questo caso la funzione non può essere di tipo void ma int perchè deve ritornare al main un valore di tipo int (tot)
    int tot;
    tot = n + m;
    return tot; //ritorna al main in valore di tot
}

//funzione media
float media(int tot){
    float media;
    media = (float)tot/2;
    return media;
}

int main(){

    stampa(); //chiamata funzione stampa

    
    int n = 3;
    int m = 4;
    int tot;
    tot = somma(n, m); //chiamata alla funzione somma       salvo anche il valore di ritorno (return) in una variabile dello stesso tipo della funzione chiamata(int)
    cout<<endl<<tot;


    float ris;
    ris = media(tot);  //chiamata alla funzione media
    cout<<endl<<ris;

    return 0;
}