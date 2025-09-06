#ifndef EXPIRATION_DATE_H
#define EXPIRATION_DATE_H

#include <string>

class ExpirationDate{
public:
    ExpirationDate(int month, int year) : mMonth{month},mYear{year} { }

    ExpirationDate(const ExpirationDate& e) : ExpirationDate(e.mMonth,e.mYear){ //costruttore copia ,Copy constructor is used to initialize the members of a newly created object
                                                                              //by copying the members of an already existing object.
                                                                              //Copy constructor takes a reference to an object of the same class as an argument.
    }

    int getMonth()const{
        return mMonth;
    }

    int getYear()const{
        return mYear;
    }

    std::string str()const{
        return std::to_string(mMonth)+'/'+std::to_string(mYear);
    }



private:
    int mMonth,mYear;


};
#endif // EXPIRATION_DATE_H
