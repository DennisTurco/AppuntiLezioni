/*
La classe Person dovrebbe avere la seguente interfaccia pubblica:

    Person(const std::string& name, const std::string& surname, unsigned age);

    Person(const Person& p);

    ~Person();

    std::string getName() const;

    std::string getSurname() const;

    unsigned int getAge() const;

    std::string str() const;
    */

#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
public:
    Person(const std::string &name, const std::string &surname, unsigned age)
    {
        _name = name;
        _surname = surname;
        _age = age;
    }

    Person(const Person &p)
    { 
        _name = p.getName();
        _surname = p.getSurname(); 
        _age = p.getAge();
    }

    ~Person() {}

    // GETTER
    std::string getName() const
    {
        return _name;
    }

    std::string getSurname() const
    {
        return _surname;
    }

    unsigned int getAge() const
    {
        return _age;
    }

    // SETTER
    void setName(std::string name) {
        _name = name;
    }

    void setSurname(std::string surname) {
        _surname = surname;
    }
    
    void setAge(unsigned long age) {
        _age = age;
    }

    std::string str() const
    {
        return _name + " " + _surname;
    }

    void print(const Person& p) {
        p.str();
    }

private:
    std::string _name, _surname;
    unsigned long _age;
};

std::ostream& operator<<(std::ostream& os, const Person& s) {
	return os << s.str();
}

#endif // PERSON_H