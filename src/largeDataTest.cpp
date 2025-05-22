#include <iostream>
#include <fstream>
#include <chrono>
#include <cassert>

#include "PATypes/BinTree.h"
#include "PATypes/Set.h"

double square(double a) {
	return a * a;
}

int main(int argc, char** argv) {
// insert test
	int AMOUNT = atoi(argv[1]);
	char* testFilename = "../contrib/8test.input";
	std::ifstream inputData;
	inputData.open(testFilename);
	if (inputData.fail()) {
		throw std::runtime_error("файл не найден!");
	}
	size_t dataAmount;
	std::chrono::_V2::steady_clock::time_point start;
	std::chrono::_V2::steady_clock::time_point end;
	inputData >> dataAmount;
	dataAmount = AMOUNT;
	PATypes::Set<double> set;
	for (int i = 0; i < dataAmount; ++i) {
		double current;
		inputData >> current;
		if (false) {
			start = std::chrono::steady_clock::now();
			std::cout << i << ": ";
			set.insert(current);
			end = std::chrono::steady_clock::now();
			std::chrono::duration<double> elapsed = end - start;
			std::cout << elapsed.count() << "\n";
		} else {
			set.insert(current);
		}
	}

// Union test
	std::cout << "Running union test\n";
	char* testFilenameAlt = "../contrib/8test.input";
	std::ifstream inputDataAlt;
	inputDataAlt.open(testFilenameAlt);
	if (inputDataAlt.fail()) {
		throw std::runtime_error("файл не найден!");
	}
	PATypes::Set<double> set2;
	inputDataAlt >> dataAmount;
	dataAmount = AMOUNT;
	for (int i = 0; i < dataAmount; ++i) {
		double current;
		inputDataAlt >> current;
		set2.insert(current);
	}
	start = std::chrono::steady_clock::now();
	set.unite(set2);
	end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout << "Union test " << AMOUNT << " :" << elapsed.count() << "\n";
	std::cout << "Running map test\n";
// Map test
	start = std::chrono::steady_clock::now();
	set.map(square);
	end = std::chrono::steady_clock::now();
	elapsed = end - start;
	std::cout << "Map test " << AMOUNT << " :" << elapsed.count() << "\n";	
	return 0;
}