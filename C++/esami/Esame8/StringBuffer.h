#ifndef STRINGBUFFER_H
#define STRINGBUFFER_H

#include <string>
#include <ostream>

class StringBuffer {
public:
    /** Appends a new string. Returns this StringBuffer. */
    virtual StringBuffer& append(const std::string& s) = 0;

    /** Appends a new char. Returns this StringBuffer. */
    virtual StringBuffer& append(char c) = 0;

    /** Appends a new integer. Returns this StringBuffer. */
    virtual StringBuffer& append(int n) = 0;

    /** Returns the total string length. */
    virtual unsigned size() const = 0;

    /** Prints the resulting string to an output stream. */
    virtual void print(std::ostream& os) const = 0;

    /** Empties the StringBuffer. */
    virtual void clear() = 0;
};

#endif