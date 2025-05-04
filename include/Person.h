#include <string>
#include <iostream>

struct PersonID {
	int series;
	int number;
	friend std::istream &operator>> (std::istream &is, PersonID &id) {
		is >> id.series >> id.number;
		return is;
	}
	friend std::ostream &operator<< (std::ostream &os, const PersonID &id) {
		os << id.series << id.number;
		return os;
	}
	friend int operator== (const PersonID &a, const PersonID &b) {
		return a.series == b.series && a.number == b.number;
	}
};

class Person {
private:
	PersonID id;
	std::string firstName;
	std::string middleName;
	std::string lastName;
public:
	Person(PersonID id, std::string firstName, std::string middleName, std::string lastName) : id(id), firstName(firstName), middleName(middleName), lastName(lastName) {}
	Person() {}
	PersonID getID();
	
	std::string getFirstName() { 
		return firstName; 
	}

	std::string getMiddleName() {
		return middleName;
	}

	std::string getLastName() {
		return lastName;
	}

	friend std::istream& operator>>(std::istream& is, Person &person)
	{
		is >> person.id >> person.firstName >> person.middleName >> person.lastName;
    	return is;
	}

	friend std::ostream& operator<<(std::ostream& os, const Person &person)
	{
		os << person.id << person.firstName << person.middleName << person.lastName;
    	return os;
	}

	friend int operator== (const Person &a, const Person &b) {
		return a.id == b.id && a.firstName == b.firstName && a.middleName == b.middleName && a.lastName == b.lastName;
	}

};