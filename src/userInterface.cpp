#include <iostream>

#include "PATypes/Sequence.h"
#include "PATypes/Stack.h"
#include "PATypes/Queue.h"
#include "PATypes/Deque.h"
#include "PATypes/Set.h"

#include "Person.h"
#include "argParser.h"
#include "hanoiTowers.h"

#include <complex>

template<class T>
void outputSequence(PATypes::Sequence<T> *sequence) {
	if (sequence->getLength() > 0)
		std::cout << sequence->getFirst() << " ";
	for (PATypes::IEnumerator<T> *enumerator = sequence->getEnumerator(); enumerator->moveNext();) {
		std::cout << enumerator->current() << " ";
	}
}

template<class T, class U>
U *inputSequence() {
	U *newSequence;

	int count = 0;
	std::cout << "Введите количество элементов: "; 
	std::cin >> count;
	T* items = new T[count];
	std::cout << "Введите элементы (через любой whitespace символ): ";
	for (int i = 0; i < count; ++i) {
		std::cin >> items[i];
	}

	newSequence = new U(items, count);
	
	delete[] items;

	return newSequence;
}

int promptMainMenu() {
	int i = 0;
	std::cout << "1. Двоичное дерево\n2. Множество\n3. Выйти\n>>> ";
	std::cin >> i;
	return i;
}

int promptType() {
	int i = 0;
	std::cout << "Выберите тип данных:\n1. Целые числа\n2. Вещественные числа\n3. Комплексные числа\n4. Студенты\n5. Преподаватели\n>>> ";
	std::cin >> i;
	return i;

}

template<class T>
void setTest() {
	PATypes::Set<T> set;
	PATypes::Set<T> set2;
	int op;
	T val;
	PATypes::Sequence<T> *seq;
	while(true) {
		std::cout << "1. Вставить\n2. Убрать\n3. Проверить на вхождение\n4. Объединить\n5. Пересечь\n6. Вычесть\n7. Проверить на включение\n8. Проверить на равенство\n9. Выйти\n>>> ";
		std::cin >> op;
		switch(op) {
			case 1:
				std::cout << "Введите значение\n>>> ";
				std::cin >> val;
				set.insert(val);
				break;
			case 2:
				try {
					set.erase(val);
				} catch (std::exception&) {
					std::cout << "Ошибка: нет такого элемента в множестве!" << "\n";
				}
				break;
			case 3:
				std::cout << "Введите значение\n>>> ";
				std::cin >> val;
				if (set.contains(val))
					std::cout << "Входит в множество" << "\n";
				else 
					std::cout << "Не входит в множество\n";
				break;
			case 4:
				seq = inputSequence<T, PATypes::MutableArraySequence<T>>();
				set2 = PATypes::Set<T>();
				if (seq->getLength() > 0)
					set2.insert(seq->getFirst());
				for (PATypes::IEnumerator<T> *enumerator = seq->getEnumerator(); enumerator->moveNext();) {
					set2.insert(enumerator->current());
				}
				set.unite(set2);
				break;
			case 5:
				seq = inputSequence<T, PATypes::MutableArraySequence<T>>();
				set2 = PATypes::Set<T>();
				if (seq->getLength() > 0)
					set2.insert(seq->getFirst());
				for (PATypes::IEnumerator<T> *enumerator = seq->getEnumerator(); enumerator->moveNext();) {
					set2.insert(enumerator->current());
				}
				set.intersect(set2);
				break;
			case 6:
				seq = inputSequence<T, PATypes::MutableArraySequence<T>>();
				set2 = PATypes::Set<T>();
				if (seq->getLength() > 0)
					set2.insert(seq->getFirst());
				for (PATypes::IEnumerator<T> *enumerator = seq->getEnumerator(); enumerator->moveNext();) {
					set2.insert(enumerator->current());
				}
				set.difference(set2);
				break;
			case 7:
				seq = inputSequence<T, PATypes::MutableArraySequence<T>>();
				set2 = PATypes::Set<T>();
				if (seq->getLength() > 0)
					set2.insert(seq->getFirst());
				for (PATypes::IEnumerator<T> *enumerator = seq->getEnumerator(); enumerator->moveNext();) {
					set2.insert(enumerator->current());
				}
				if (set.hasSubSet(set2)) {
					std::cout << "Данное множество входит\n";
				} else {
					std::cout << "Данное множество не входит\n";
				}
				break;
			case 8:
				seq = inputSequence<T, PATypes::MutableArraySequence<T>>();
				set2 = PATypes::Set<T>();
				if (seq->getLength() > 0)
					set2.insert(seq->getFirst());
				for (PATypes::IEnumerator<T> *enumerator = seq->getEnumerator(); enumerator->moveNext();) {
					set2.insert(enumerator->current());
				}
				if (set.equal(set2)) {
					std::cout << "Множества равны\n";
				} else {
					std::cout << "Множества не равны\n";
				}
				break;
			case 9:
				exit(0);
				break;
		}
	}
}

int main(int argc, char *argv[]) {
	PATypes::MutableListSequence<std::string> argvList;
	for (int i = 0; i < argc; ++i) {
		argvList.append(std::string(argv[i]));
	}
	ArgParser::ArgumentParser argParser;
	argParser.parseArguments(&argvList);
	bool running = true;
	while(running) {
		switch(promptMainMenu())
		{
			case 2:
				switch(promptType()) {
					case 1:
						setTest<int>();
						break;
					case 2:
						setTest<double>();
						break;
					case 3:
						setTest<std::complex<double>>();
						break;
					case 4:
						setTest<Person>();
						break;
					case 5:
						setTest<Person>();
						break;
				}
				break;
			case 1:
				break;
			case 3:
				running = false;
				break;
		}
	}
	return 0;
}