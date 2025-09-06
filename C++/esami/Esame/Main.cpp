/*
1) Creare una classe Person da cui derivare le classi Student e Worker. 
Una persona è caratterizzata da un nome, cognome, ed età. 
Uno studente è una persona che ha anche un numero di matricola. 
Un lavoratore è una persona con un tipo di lavoro.

La classe Person dovrebbe avere la seguente interfaccia pubblica:

	Person(const std::string& name, const std::string& surname, unsigned age);

	Person(const Person& p);

	~Person();

	std::string getName() const;

	std::string getSurname() const;

	unsigned int getAge() const;

	std::string str() const;


La classe Student (che estende Person) dovrebbe avere:

	Student(const std::string& name, const std::string& surname, unsigned age, unsigned long id);

	Student(const Person& p, unsigned long id);

	Student(const Student& s): Student(s,id);

	~Student();

	unsigned long getId() const;


La classe Worker (che estende Person) invece dovrebbe avere:
	Worker(const std::string& name, const std::string& surname, unsigned int age, const std::string& job);

	Worker(const Person& p, const char* job);

	Worker(const Worker& w);

	~Worker();

	std::string getJob() const;


Con queste classi provare il seguente codice:

	Person p1("Alice","Bianchi",23);
	cout << "Person: " << p1.str() << ", age: " << p1.getAge() << endl;

	Student s1(p1.getName(),p1.getSurname(),p1.getAge(),12345);
	cout << "Student: " << s1.str() << ", id: " << s1.getId() << endl;

	Student s2(p1,55555);
	cout << "Student: " << s1.str() << ", id: " << s1.getId() << endl;

	Worker w1(p1,"Ingegnere");
	cout << "Worker: " << w1.str() << ", job: " << w1.getJob() << endl;



2) Sovraccaricare l'operatore << in modo da scrivere un oggetto Person su ostream.
Sulla base del nuovo operatore scrivere tre funzioni print():
	void print(const Person& p);
	void print(const Student& p);
	void print(const Worker& p);

e provare il seguente codice:
	Person p1("Alice","Bianchi",23);
	print(p1);
	Student s1(p1.getName(),p1.getSurname(),p1.getAge(),12345);
	print(s1);
	Student s2(p1,55555);
	print(s2);
	Worker w1(p1,"Ingegnere");
	print(w1);



3) Separare la definizione delle classi (file *.h) dalla loro implementazione (file *.cpp).
*/

#include <iostream>
#include "Student.h"
#include "Person.h"
#include "Worker.h"

using namespace std;

int main()
{
	Person p1("Alice", "Bianchi", 23);
	cout << "Person: " << p1.str() << ", age: " << p1.getAge() << endl;
	
	Student s1(p1.getName(), p1.getSurname(), p1.getAge(), 12345);
	cout << "Student: " << s1.str() << ", id: " << s1.getId() << endl;

	Student s2(p1, 55555);
	cout << "Student: " << s1.str() << ", id: " << s1.getId() << endl;

	Worker w1(p1, "Ingegnere");
	cout << "Worker: " << w1.str() << ", job: " << w1.getJob() << endl;
	

	Worker w2 = w1;
	cout << "Worker: " << w2.str() << ", job: " << w2.getJob() << endl;

	return 0;
}