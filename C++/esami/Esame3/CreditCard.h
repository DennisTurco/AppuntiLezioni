#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H
#include "ExpirationDate.h"

class CreditCard{
public:
    CreditCard (const std::string& first_name, const std::string& last_name, const std::string& number, const ExpirationDate& expire):mFirstName{first_name},mSecondName{last_name},mNumber{number},mExpire{expire} {}

    CreditCard (const CreditCard& c):CreditCard (c.mFirstName,c.mSecondName,c.mNumber,c.mExpire) { //costruttore copia
    }

    std::string getFirstName()const{
        return mFirstName;
    }

    std::string getLastName()const{
        return mSecondName;
    }

    std::string getNumber()const{
        return mNumber;
    }

    ExpirationDate getExpirationDate() const{
        return mExpire;
    }

    std::string str() const{
        return mFirstName+", "+mSecondName+", "+mNumber+", "+mExpire.str();
    }




private:
    std::string mFirstName, mSecondName, mNumber;
    ExpirationDate mExpire; // oggetto della classe ExpirationDate

} ;
#endif // CREDIT_CARD_H

