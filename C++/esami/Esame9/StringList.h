#ifndef STRINGLIST_H
#define STRINGLIST_H
#include <string>

class StringList {
public:
    /** Adds a new element at the beginning of the list. */
    virtual void push_front(std::string elem) = 0;

    /** Adds a new element at the end of the list. */
    virtual void push_back(std::string elem) = 0;

    /** Returns the element at the given position with bounds checking. */
    virtual std::string at(unsigned index) const = 0;

    /** remove the element at the given position. */
    virtual void remove(unsigned index) = 0;

    /** Returns the number of elements in the list. */
    virtual unsigned size() const = 0;

    /** Clears all elements of the vector to make it empty. */
    virtual void clear() = 0;

    /** Gets a string representation of the list. */
    virtual std::string str() const = 0;
};

#endif