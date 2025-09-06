#include <iostream>
#include <string>
#include <windows.h>
#include "funzioniAtleti.h"

using namespace std;

int main (){
    
    int scelta;
    int n;
    float tempo;
    int atleti_inseriti = 0;
    cout<<"quanti atleti partecipano alla maratona di New York? ";
    cin>>n;
    atleta atleti[n];

    //menù
    do{
        cout<<"Scegli:\n1) Assegna i tempi;\n2) Per calcolare la media;\n3) Per stampare i tempi degli atleti;\n4) Per sapere il tempo minore;\n5) Per vedere i numeri sotto la media;\n6) Per sapere quanti numeri sono inferiori al parametro inserito;\n7) Per inserire le informazioni dell'atleta;\n8) Stampa atleti;\n0) Per uscire;\nOperazione: ";
        cin>>scelta;

        switch(scelta){
            case 1:
                cout << "inserimento tempi atleti..." << endl;
                tempo_atleti(atleti, atleti_inseriti);
                cout << "inserimento completato." << endl;
                break;
            case 2:
                cout<<"la media e': "<<calcolaMedia(atleti, atleti_inseriti)<<" minuti"<<endl;
                break;
            case 3:
                stampa_tempo(atleti, atleti_inseriti);
                break;
            case 4:
                cout<<"il tempo minore e': "<<numeroMin(atleti, atleti_inseriti)<<" minuti"<<endl;
                break;
            case 5:
                sottoVettore(atleti, atleti_inseriti);
                break;
            case 6:
                cout<<"inserisci un tempo: ";
                cin>>tempo;
                cout<< tempoInferiore(atleti, atleti_inseriti, tempo)<<endl;
                break;
            case 7:

                if (atleti_inseriti >= n){
                    cout << "Non e' possibile aggiungere ulteriori atleti. Numero massimo raggiunto.\n";
                    break;
                }

                cout<<"Inserisci il nome della persona: ";
                cin>>atleti[atleti_inseriti].nome;
                cout<<"Inserisci il cognome della persona: ";
                cin>>atleti[atleti_inseriti].cognome;
                cout<<"Inserisci il numero di gara della persona: ";
                cin>>atleti[atleti_inseriti].numerogara;
                cout<<"Inserisci l'eta' della persona: ";
                cin>>atleti[atleti_inseriti].eta;
                cout<<"Inserisci il sesso della persona (M o F): ";
                cin>>atleti[atleti_inseriti].sesso;

                atleti_inseriti++;

                break;
            case 8:
                for (int i = 0; i < atleti_inseriti; i++) {
                    cout << "\nAtleta " << i+1 << ":" << endl;
                    cout<<"Nome: "<<atleti[i].nome<<endl;
                    cout<<"Cognome: "<<atleti[i].cognome<<endl;
                    cout<<"Data di nascita: "<<atleti[i].eta<<endl;
                    cout<<"Numero concorrente: "<<atleti[i].numerogara<<endl;
                    cout<<"Sesso: "<<atleti[i].sesso<<endl;
                }
                break;
            default:
                cout<<"scelta non possibile"<<endl;
        }
        
        system("pause");//premi un tasto per continuare
        system("cls");//pulisce lo schermo

    } while(scelta!=0);//esce se si preme il tasto 0
    return 0;
}