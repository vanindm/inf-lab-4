#include <cassert>
#include <complex>
#include <iostream>
#include <string>

#include "PATypes/Queue.h"
#include "Person.h"

int main() {
	PATypes::Queue<int> intTest;
	intTest.push(1);
	intTest.push(2);
	intTest.push(3);
	intTest.push(100);
	assert(intTest.pop() == 1);
	assert(intTest.pop() == 2);
	assert(intTest.pop() == 3);
	assert(intTest.pop() == 100);
	PATypes::Queue<double> realTest;
	realTest.push(1.2);
	realTest.push(2.4);
	realTest.push(3.6);
	realTest.push(100.100);
	assert(realTest.pop() == 1.2);
	assert(realTest.pop() == 2.4);
	assert(realTest.pop() == 3.6);
	assert(realTest.pop() == 100.100);
	PATypes::Queue<std::complex<double>> compTest;
	compTest.push(std::complex<double>(7,8));
	compTest.push(std::complex<double>(5,6));
	compTest.push(std::complex<double>(3,4));
	compTest.push(std::complex<double>(1,2));
	assert(compTest.pop() == std::complex<double>(7,8));
	assert(compTest.pop() == std::complex<double>(5,6));
	assert(compTest.pop() == std::complex<double>(3,4));
	assert(compTest.pop() == std::complex<double>(1,2));
	PATypes::Queue<Person> personTest;
	personTest.push(Person({1,2}, "Avery", "Lee", "Ivanovich"));
	personTest.push(Person({3,4}, "Lorem", "Lee", "Ivanovich"));
	personTest.push(Person({5,6}, "Ivanov", "Lee", "Ivanovich"));
	personTest.push(Person({7,8}, "BillGates", "Lee", "Ivanovich"));
	assert(personTest.pop() == Person({1,2}, "Avery", "Lee", "Ivanovich"));
	assert(personTest.pop() == Person({3,4}, "Lorem", "Lee", "Ivanovich"));
	assert(personTest.pop() == Person({5,6}, "Ivanov", "Lee", "Ivanovich"));
	assert(personTest.pop() == Person({7,8}, "BillGates", "Lee", "Ivanovich"));
	std::cout << "SUCCESS" << std::endl;

	return 0;
}