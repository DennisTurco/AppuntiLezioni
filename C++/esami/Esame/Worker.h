/*
La classe Worker (che estende Person) invece dovrebbe avere:
    Worker(const std::string& name, const std::string& surname, unsigned int age, const std::string& job);

    Worker(const Person& p, const char* job);

    Worker(const Worker& w);

    ~Worker();

    std::string getJob() const;
*/

#ifndef WORKER_H
#define WORKER_H

#include "Person.h"
class Worker : public Person
{
public:
    Worker(const std::string& name, const std::string& surname, unsigned int age, const std::string& job) : Person(name, surname, age) {
        _job = job;
    }

    Worker(const Person& p, const char* job) : Person(p) {
        _job = job;
    }

    // SISTEMATO
    // usiamo il costruttore di copia (gia' definito in Person per copiare le informazioni che gestisce Person), poi copiamo il _job
    Worker(const Worker& w) : Person(w) {
        _job = w.getJob();
    }

    ~Worker() { }

    std::string getJob() const {
        return _job;
    }

    void print(const Worker& p) {
        std::cout << p;
    }

private:
    std::string _job;
};

#endif 