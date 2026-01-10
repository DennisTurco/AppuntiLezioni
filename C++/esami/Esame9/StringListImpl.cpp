#include "StringListImpl.h"
#include <sstream>

void StringListImpl::push_front(std::string elem) {
    data.insert(data.begin(), elem);
}

void StringListImpl::push_back(std::string elem) {
    data.push_back(elem);
}

std::string StringListImpl::at(unsigned index) {
    if (index >= data.size()) {
        return "";
    }

    return data[index];
}

void StringListImpl::remove(unsigned index) {
    if (index >= data.size()) {
        return;
    }
    data.erase(data.begin() + index);
}

unsigned StringListImpl::size() const {
    return data.size();
}

void StringListImpl::clear() {
    data.clear();
}

std::string StringListImpl::str() const {
    std::ostringstream oss;
    for (auto& s : data) {
        oss << s << " - ";
    }
    return oss.str();
}

std::ostream &operator<<(std::ostream &os, const StringList &sl) {
    os << sl.str();
    return os;
}
