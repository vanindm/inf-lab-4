#include <cassert>
#include <string>
#include <complex>
#include <iostream>

#include "Person.h"
#include "PATypes/Deque.h"

int main() {
	PATypes::Deque<int> intTest;
	intTest.push_front(1);
	intTest.push_front(2);
	intTest.push_front(3);
	intTest.push_back(100);
	assert(intTest.pop_back() == 100);
	assert(intTest.pop_front() == 3);
	assert(intTest.pop_front() == 2);
	assert(intTest.pop_front() == 1);
	PATypes::Deque<double> realTest;
	realTest.push_back(1.2);
	realTest.push_back(2.4);
	realTest.push_back(3.6);
	realTest.push_front(100.100);
	assert(realTest.pop_front() == 100.100);
	assert(realTest.pop_back() == 3.6);
	assert(realTest.pop_back() == 2.4);
	assert(realTest.pop_back() == 1.2);
	PATypes::Deque<std::complex<double>> compTest;
	compTest.push_front(std::complex<double>(1,2));
	compTest.push_front(std::complex<double>(3,4));
	compTest.push_front(std::complex<double>(5,6));
	compTest.push_front(std::complex<double>(7,8));
	assert(compTest.pop_back() == std::complex<double>(1,2));
	assert(compTest.pop_back() == std::complex<double>(3,4));
	assert(compTest.pop_back() == std::complex<double>(5,6));
	assert(compTest.pop_back() == std::complex<double>(7,8));
	PATypes::Deque<Person> personTest;
	personTest.push_front(Person({1,2}, "Avery", "Lee", "Ivanovich"));
	personTest.push_front(Person({3,4}, "Lorem", "Lee", "Ivanovich"));
	personTest.push_front(Person({5,6}, "Ivanov", "Lee", "Ivanovich"));
	personTest.push_back(Person({7,8}, "BillGates", "Lee", "Ivanovich"));
	assert(personTest.pop_front() == Person({5,6}, "Ivanov", "Lee", "Ivanovich"));
	assert(personTest.pop_front() == Person({3,4}, "Lorem", "Lee", "Ivanovich"));
	assert(personTest.pop_front() == Person({1,2}, "Avery", "Lee", "Ivanovich"));
	assert(personTest.pop_front() == Person({7,8}, "BillGates", "Lee", "Ivanovich"));
	std::cout << "SUCCESS" << std::endl;
	return 0;
}