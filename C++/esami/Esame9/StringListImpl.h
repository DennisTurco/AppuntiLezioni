#ifndef STRINGLISTIMPL_H
#define STRINGLISTIMPL_H

#include "StringList.h"
#include "vector"

class StringListImpl : public StringList {
private:
    std::vector<std::string> data;
public:
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