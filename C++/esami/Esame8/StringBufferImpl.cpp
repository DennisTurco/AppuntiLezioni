#include "StringBufferImpl.h"
#include <sstream>
#include <memory>

StringBuffer& StringBufferImpl::append(const std::string& s) {
    data.push_back(s);
    return *this;
}

StringBuffer& StringBufferImpl::append(char c) {
    data.push_back(std::string(1, c)); // 1 = numero caratteri, c = carattere
    return *this;
}

StringBuffer& StringBufferImpl::append(int n) {
    data.push_back(std::to_string(n));
    return *this;
}

unsigned StringBufferImpl::size() const {
    unsigned total = 0;
    for (const auto& s : data) {
        total += s.size();
    }
    return total;
}

void StringBufferImpl::print(std::ostream& os) const {
    for (const auto& s : data) {
        os << s;
    }
}

void StringBufferImpl::clear() {
    data.clear();
}

std::ostream& operator<<(std::ostream& os, const StringBuffer& sb) {
    sb.print(os);
    return os;
}

void read(const std::string& file_name, StringBuffer& sb) {
    std::ifstream file(file_name);
    std::string linea;

    while (std::getline(file, linea)) {
        sb.append(linea).append('\n');
    }
}

std::unique_ptr<StringBuffer> read(const std::string& file_name) {
    auto sb = std::make_unique<StringBufferImpl>();
    read(file_name, *sb);
    return sb;
}