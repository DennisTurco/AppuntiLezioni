/*
La classe Student (che estende Person) dovrebbe avere:

    Student(const std::string& name, const std::string& surname, unsigned age, unsigned long id);

    Student(const Person& p, unsigned long id);

    Student(const Student& s): Student(s,id);

    ~Student();

    unsigned long getId() const;
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Person.h"

class Student : public Person
{
public:
    Student(const std::string& name, const std::string& surname, unsigned age, unsigned long id) : Person(name, surname, age) {
        _id = id;
    }

	Student(const Person& p, unsigned long id) : Person(p) {
        _id = id;
    }

	Student(const Student& s): Student(s, _id) {

    }

	~Student() { }

	unsigned long getId() const {
        return _id;
    }

    void print(const Student& p) {
        std::cout << p;
    }

private:
    unsigned long _id;
};


#endif