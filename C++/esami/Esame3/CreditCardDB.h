#ifndef CREDIT_CARD_DB
#define CREDIT_CARD_DB

#include"CreditCard.h"
#include<string>
#include <vector>
#include<exception>
#include<iostream>


class CreditCardDB{
public:
    CreditCardDB(){}

    //metodo add() per aggiungere un nuova carta di credito
    void add(const CreditCard& c){
        cards.push_back(c); //
    }

    // un metodo getCardByNumber() per ottenere la carta con un numero dato
    CreditCard getCardByNumber(const std::string& number)const{ //metodo che mi ritorna un oggetto CreditCard????
        for(const auto& c:cards) {
            if(c.getNumber() == number)
                return c; 
        }
        
        throw std::runtime_error("credit card not found with number: " + number); // perhc� mi da sempre l'else  */
    }

    //metodo getAllCardNumbers() che restituisce un vettore con tutti i numeri delle carte di credito presenti.
    std::vector<std::string> getAllCardNumbers()const{
        std::vector<std::string> all_numbers;
        for(const auto& c:cards){
            all_numbers.push_back(c.getNumber());
        }
        return all_numbers;
        }

    //metodo che cancella dall�archivio tutte le carte scadute (con scadenza prima della data specificata da not_before).
    void removeExpiredCards(const ExpirationDate& not_before){
        // Utilizzando ciclo for con indice:
		for (int i= cards.size()-1; i>=0; --i) {
			ExpirationDate expire= cards[i].getExpirationDate();
			bool expired= expire.getYear()<not_before.getYear() ||(expire.getYear()==not_before.getYear() && expire.getMonth()<not_before.getMonth());
			if (expired) cards.erase(cards.begin()+i); //erase rimuove oggetto in una certa posizione
		}
		/*// Utilizzando ciclo for con iterator:
		for (auto it= cards.begin(); it!=cards.end(); ) {
			ExpirationDate expire= it->getExpirationDate();
			bool expired= expire.getYear()<not_before.getYear() ||(expire.getYear()==not_before.getYear() && expire.getMonth()<not_before.getMonth());
			if (expired) it= cards.erase(it); // nota: erase() restituisce un iterator che punta l'elemento successivo
			else ++it;
		}*/
    }


private:
    std::vector<CreditCard> cards; //il testo mi dice "un insieme di oggetti, uso vettore di oggetti chiamato cards

};
#endif // CREDIT_CARD_DB

