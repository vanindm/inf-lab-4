#include <cassert>
#include <string>

#include "PATypes/Stack.h"

int main() {
	PATypes::Stack<int> intTest;
	intTest.push(1);
	intTest.push(2);
	intTest.push(3);
	assert(intTest.pop() == 3);
	assert(intTest.pop() == 2);
	assert(intTest.pop() == 1);
	return 0;
}