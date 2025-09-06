/*
Si vuole gestire un archivio di carte di credito. A tal fine si chiede di:
1) Creare le seguenti classi con i rispettivi costruttori e metodi pubblici:
ExpirationDate
ExpirationDate(int month, int year)
ExpirationDate(const ExpirationDate& e)
int getMonth()
int getYear()
string str()

CreditCard
CreditCard (const string& first_name, const string& last_name,
const string& number, const ExpirationDate& expire)
CreditCard(const CreditCard& c)
string getFirstName()
string getLastName()
string getNumber()
ExpirationDate getExpirationDate()
string str()

CreditCardDB
CreditCardDB()
void add(const CreditCard& card)
CreditCard getCardByNumber(const string& number)
vector<string> getAllCardNumbers()

La classe CreditCard mantiene quattro tipi di informazione: il nome del proprietario (first name), il cognome
(last name), il numero della carta salvato come stringa e la data di scadenza (expiration date). Quest�ultima
� gestita tramite la classe ExpirationDate che matiene il mese e l�anno si scadenza. I metodi str() di
CreditCard e di ExpirationDate restituiscono una stringa che descrive il rispettivo oggetto.
La classe CreditCardDB mantiene un insieme di oggetti di tipo CreditCard e possiede un metodo add() per
aggiungere un nuova carta di credito, un metodo getCardByNumber() per ottenere la carta con un numero
dato, e un metodo getAllCardNumbers() che restituisce un vettore con tutti i numeri delle carte di credito
presenti.
Quando opportuno usare il qualificatore �const� per i vari metodi.
Il file test.cpp � un esempio di codice che pu� essere usato per verificare le funzionalit� di queste classi .

2) Scrivere un programma �read_creditcards.cpp� che legge dal file �creditcards.txt� i dati di una sequenza
di carte di credito, li salva in un oggetto di tipo CreditCardDB, e stampa il contenuto dell�archivio.

3) In CreditCardDB aggiungere il metodo void removeExpiredCards(const ExpirationDate& not_before)
che cancella dall�archivio tutte le carte scadute (con scadenza prima della data specificata da
not_before).

Modificare il programma creditcards.cpp rimuovendo dall�archivio tutte le carte con scadenza antecedente
09/2022 e stampare l�archivio aggiornato.
*/

#include <fstream>
#include <iostream>
#include<sstream>
#include <string>
#include "ExpirationDate.h"
#include "CreditCard.h"
#include "CreditCardDB.h"
#include "punto1.cpp"

using namespace std;

int main()
{
	punto1();

	//punto 2

	//apro file
	/*string filename="creditcards.txt";
	ifstream filein{filename};
	if(!filein.is_open()){ // cerco di aprire il file
        cerr<<"impossibile leggere il file 'creditcards.txt'"<<endl;
	}

	//leggo le carte
	CreditCardDB db;
	string first_name,last_name,number,expire_str;
	while(getline(filein,first_name)){
        getline(filein,last_name);
        getline(filein,number);
        getline(filein,expire_str);
        istringstream ss{expire_str};
        string month, year;
        getline(ss,month,'/'); //salvo in month quello che legge prima di '/'
        ss>>year;
        ExpirationDate expire(stoi(month),stoi(year)); //stoi converte stringa in intero
        CreditCard card(first_name,last_name,number,expire); //inizializzo oggetto CreditCard
        db.add(card); //salvo nell'oggetto di CreditCardDB
	}
	filein.close();

	cout<<"All cards:\n";
	for(const auto n:db.getAllCardNumbers()){
        cout<<db.getCardByNumber(n).str()<<endl;
	}
	*/

	cout<<endl;



	//punto 3
	// rimuovi le carte scadute
	ExpirationDate date(10,2024);
	cout<<"Expiration date: "<<date.str()<<endl<<endl;

	CreditCard card1("Alice","Bianchi","111122223333",date);
	cout<<"Card: "<<card1.str()<<endl;

	CreditCard card2("Marco","Neri","222233334444",date);
	cout<<"Card: "<<card2.str()<<endl<<endl;

	CreditCardDB db;
	db.add(card1);
	db.add(card2);
	db.removeExpiredCards(ExpirationDate(9,2022));
	cout<<"Valid cards:\n";
	for (const auto& n: db.getAllCardNumbers()) cout<<db.getCardByNumber(n).str()<<endl;
	//cout<<db.getCardByNumber("23415674324").str()<<endl;
	cout<<endl;
    return 0;
}
