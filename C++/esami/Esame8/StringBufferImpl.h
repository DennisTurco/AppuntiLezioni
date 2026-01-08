#ifndef STRINGBUFFERIMPL_H
#define STRINGBUFFERIMPL_H

#include "StringBuffer.h"
#include <vector>
#include <string>
#include <memory>

class StringBufferImpl : public StringBuffer {
private:
    std::vector<std::string> data;
public:
    StringBuffer& append(const std::string& s) override;
    StringBuffer& append(char c) override;
    StringBuffer& append(int n) override;
    unsigned size() const override;
    void print(std::ostream& os) const override;
    void clear() override;
};

void read(const std::string& file_name, StringBuffer& sb);
std::unique_ptr<StringBuffer> read(const std::string& file_name);
std::ostream& operator<<(std::ostream& os, const StringBuffer& sb);

#endif