#include <fstream>
#include <iostream>
#include<sstream>
#include <string>
#include "ExpirationDate.h"
#include "CreditCard.h"
#include "CreditCardDB.h"

using namespace std;

void punto1() {
    ExpirationDate date(10,2024);
	cout<<"Expiration date: "<<date.str()<<endl<<endl;

	CreditCard card1("Alice","Bianchi","111122223333",date);
	cout<<"Card: "<<card1.str()<<endl;

	CreditCard card2("Marco","Neri","222233334444",date);
	cout<<"Card: "<<card2.str()<<endl<<endl;

	CreditCardDB db;
	db.add(card1);
	db.add(card2);

	cout<<"All card numbers:\n";
	for (const auto& n : db.getAllCardNumbers()){
        cout<<n<<endl;
	}
	cout<<endl;

	CreditCard card3= db.getCardByNumber("111122223333"); //se non commento l'else non funziona per la seconda carta
	cout<<"The card n. "<<card3.getNumber()<<" expires on "<<card3.getExpirationDate().str()<<endl;
	cout<<endl;

	// CreditCard card4= db.getCardByNumber("333344445555");
	//cout<<"The card n. "<<card4.getNumber()<<" expires on "<<card4.getExpirationDate().str()<<endl;

	try {
		CreditCard card3= db.getCardByNumber("222233334444");
		cout<<"The card n. "<<card3.getNumber()<<" expires on "<<card3.getExpirationDate().str()<<endl;

		CreditCard card4= db.getCardByNumber("333344445555");
		cout<<"The card n. "<<card4.getNumber()<<" expires on "<<card4.getExpirationDate().str()<<endl;
	}
	catch (runtime_error& e) {
		cerr<<"Error: "<<e.what()<<endl;
	}
}