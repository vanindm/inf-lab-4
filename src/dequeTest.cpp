#include <cassert>
#include <string>

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
	return 0;
}