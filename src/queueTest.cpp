#include <cassert>
#include <string>

#include "PATypes/Queue.h"

int main() {
	PATypes::Queue<int> intTest;
	intTest.push(1);
	intTest.push(2);
	intTest.push(3);
	assert(intTest.pop() == 1);
	assert(intTest.pop() == 2);
	assert(intTest.pop() == 3);
	return 0;
}