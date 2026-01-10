#include "StringListImpl2.h"

StringListImpl2::StringListImpl2() : capacity(5), lenght(0) {
    data = new std::string[capacity];
}

StringListImpl2::~StringListImpl2() {
    delete[] data;
}

void StringListImpl2::resize(unsigned new_cap) {
    std::string* new_data = new std::string[new_cap];
    for (int i = 0; i < lenght; ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_cap;
}

void StringListImpl2::push_back(std::string elem) {
    if (lenght == capacity) {
        resize(capacity + 5);
    }

    lenght++;
    data[lenght] = elem;
}

void StringListImpl2::push_front(std::string elem) {
    if (length == capacity) {
        resize(capacity * 2);
    }

    for (int i = length; i > 0; --i) {
        data[i] = data[i - 1];
    }

    data[0] = elem;
    ++length;
}

std::string StringListImpl2::at(unsigned index) {
    if (index >= length) {
        return "";
    }
    return data[index];
}

void StringListImpl2::remove(unsigned index) {
    if (index >= length) {
        return;
    }

    for (unsigned i = index; i + 1 < length; ++i) {
        data[i] = data[i + 1];
    }

    --length;
}

unsigned StringListImpl2::size() const {
    return length;
}

void StringListImpl2::clear() {
    length = 0;
}

std::string StringListImpl2::str() const {
    std::string result;
    for (unsigned i = 0; i < length; ++i) {
        result += (data[i] + " - ");
    }
    return result;
}

std::ostream &operator<<(std::ostream &os, const StringList &sl) {
    os << sl.str();
    return os;
}
