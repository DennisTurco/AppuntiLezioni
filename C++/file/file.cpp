#include<iostream>
#include<cstring>
using namespace std;

int main(){
    
    //Passo 1
    FILE *fp;  //dichiarazione file di nome fp
    char nomefile[32];
    char stringa[32];

    cout<<"Nome File: ";
    cin>>nomefile;

    //Passo 2
    fp = fopen(nomefile, "a");  //apertura file

    //Passo 3 -- Operazioni
    fputs("ciao bellissimo", fp);
    fgets(stringa, 10, fp);
    cout<<stringa;

    //Passo 4 -- Chiusura del file
    fclose(fp);

    return 0;
}