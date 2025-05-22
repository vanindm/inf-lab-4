#include <cassert>
#include <string>
#include <complex>
#include <iostream>

#include "Person.h"
#include "PATypes/BinTree.h"

bool isEven(int a) {
	return a % 2 == 0;
}

int square(int a) {
	return a * a;
}

int main() {
	PATypes::BinaryTree<int> test;
	test.insert(10);
	assert(test.getRoot()->getVal() == 10);
	assert(test.getRoot()->getVal() != 5);
	assert(test.findElement(10)->getVal() == 10);
	assert(test.findElement(5) == nullptr);
	test.insert(20);
	assert(test.findElement(20)->getVal() == 20);
	PATypes::BinaryTree<int> test2;
	test2.insert(15);
	test.merge(test2);
	assert(test.findElement(15)->getVal() == 15);
	PATypes::BinaryTree<int> whereTest(isEven, test);
	assert(whereTest.findElement(20) != nullptr);
	assert(whereTest.findElement(10) != nullptr);
	assert(whereTest.findElement(5) == nullptr);
	PATypes::BinaryTree<int>* mapTest = test.map(square);
	assert(mapTest->findElement(400) != nullptr);
	mapTest->erase(mapTest->findElement(400));
	assert(mapTest->findElement(400) == nullptr);
	assert(mapTest->findElement(225) != nullptr);
	assert(test.subTree(test) != nullptr);
	std::cout << test.KPL(" ") << std::endl;
	std::cout << "SUCCESS" << std::endl;
	delete mapTest;
	return 0;
}