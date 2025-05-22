#include <cassert>
#include <string>
#include <complex>
#include <iostream>

#include "Person.h"
#include "PATypes/Set.h"

int main() {
	PATypes::Set<int> set;
	set.insert(1);
	set.insert(2);
	set.insert(3);
	assert(set.get(0) == 1);
	std::cout << "SUCCESS" << std::endl;
	return 0;
}