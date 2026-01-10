#ifndef STRINGLISTIMPL2_H
#define STRINGLISTIMPL2_H

#include "StringList.h"

class StringListImpl2 : public StringList {
private:
    std::string* data;
    unsigned capacity; // quanti elementi massimi puo' avere
    unsigned lenght; // quanti elementi ha attualmente
    void resize(unsigned new_cap);
public:
    StringListImpl2();
    ~StringListImpl2();
    void push_front(std::string elem) override;
    void push_back(std::string elem) override;
    void std::string at(unsigned index) override;
    void remove(unsigned index) override;
    unsigned size() const override;
    void clear() override;
    std::string str() const override;
};

std::ostream& operator<<(std::ostream& os, const StringList& sl);

#endif