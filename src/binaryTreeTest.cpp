#include <cassert>
#include <string>
#include <complex>
#include <iostream>

#include "Person.h"
#include "PATypes/BinTree.h"

bool isEven(int a) {
	return a % 2 == 0;
}

bool isEven(double a) {
	return (int) a % 2 == 0;
}

int square(int a) {
	return a * a;
}

double square(double a) {
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
	PATypes::BinaryTree<double> testf;
	testf.insert(10.5);
	assert(testf.getRoot()->getVal() == 10.5);
	assert(testf.getRoot()->getVal() != 5.6);
	assert(testf.findElement(10.5)->getVal() == 10.5);
	assert(testf.findElement(5) == nullptr);
	testf.insert(20.9998);
	assert(testf.findElement(20.9998)->getVal() == 20.9998);
	PATypes::BinaryTree<double> test2f;
	test2f.insert(15.123);
	testf.merge(test2f);
	assert(testf.findElement(15.123)->getVal() == 15.123);
	PATypes::BinaryTree<double> whereTestf(isEven, testf);
	assert(whereTestf.findElement(20.9998) != nullptr);
	assert(whereTestf.findElement(10.5) != nullptr);
	assert(whereTestf.findElement(5.0) == nullptr);
	PATypes::BinaryTree<double>* mapTestf = testf.map(square);
	assert(mapTestf->findElement(440.99160004000004) != nullptr);
	mapTestf->erase(mapTestf->findElement(440.99160004000004));
	assert(mapTestf->findElement(440.99160004) == nullptr);
	assert(mapTestf->findElement(228.70512899999997) != nullptr);
	assert(testf.subTree(testf) != nullptr);
	std::cout << "SUCCESS" << std::endl;
	delete mapTest;
	delete mapTestf;
	return 0;
}