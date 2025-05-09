#include <iostream>

#include "PATypes/Sequence.h"
#include "PATypes/Stack.h"
#include "PATypes/Queue.h"
#include "PATypes/Deque.h"

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

void hanoiTowers() {
	class Green : public IColor {
	public:
		Green() {}
		virtual ~Green() {}
		virtual int getColor() {
			return 0;
		}
		virtual char getRepresentation() {
			return 'G';
		}
	};
	Green green = Green();

	class HanoiItem : public IHanoiItem {
	int area;
	IColor *color;
	public:
		HanoiItem(int area, IColor *color) : area(area), color(color) {};
		virtual ~HanoiItem() {}
		virtual int getArea() {
			return area;
		}
		IColor *getColor() {
			return color;
		}
		virtual bool compare(IHanoiItem* other) {
			return area > other->getArea();
		}
	};

	PATypes::Stack<HanoiItem *> cleanup;

	int cnt = 0;
	std::cout << "Введите количество колец\n>>> ";
	std::cin >> cnt;

	PATypes::MutableArraySequence<IHanoiItem *> items;

	for (int i = 0; i < cnt; ++i) {
		std::cout << "Введите цвет кольца " << i << "\n>>> ";
		char c = 'G';
		std::cin >> c;
		std::cout << "Введите площадь кольца " << i << "\n>>> ";
		int area;
		std::cin >> area;
		HanoiItem* newItem;
		switch(c) {
			case 'G':
				newItem = new HanoiItem(area, &green);
				cleanup.push(newItem);
				items.append(newItem);
				break;
			default:
				std::cout << "Nah!\n";
		}
	}
	int src, dst;
	std::cout << "Введите начальный стержень\n>>> ";
	std::cin >> src;
	std::cout << "Введите конечный стержень\n>>> ";
	std::cin >> dst;
	HanoiTower hanoiTower((PATypes::Sequence<IHanoiItem *> *)&items, src, dst);
	try {
		hanoiTower.solve();
	} catch (std::logic_error &error) {
		std::cout << "Задача нерешаема при текущих входных данных!\n";
		std::cout << "Ошибка: " << error.what() << "\n";
	}
	std::cout << "Задача решаема и была решена!" << "\n";
	while(cleanup.getLength()) {
		delete cleanup.pop();
	}
	return;
}

int promptMainMenu() {
	int i = 0;
	std::cout << "1. Выбрать АТД\n2. Ханойские башни\n3. Выйти\n>>> ";
	std::cin >> i;
	return i;
}

int promptType() {
	int i = 0;
	std::cout << "Выберите тип данных:\n1. Целые числа\n2. Вещественные числа\n3. Комплексные числа\n4. Студенты\n5. Преподаватели\n>>> ";
	std::cin >> i;
	return i;

}

int promptADT() {
	int i = 0;
	std::cout << "1. Стек\n2. Очередь\n3. Дек\n>>> ";
	std::cin >> i;
	return i;
}

template<class T, class DS>
void ads() {
	DS ads;
	int op;
	PATypes::Sequence<T> *seq;
	PATypes::Sequence<int> *idx;
	T val;
	while(true) {
		std::cout << "1. Вставить\n2. Убрать\n3. Найти подпоследовательность\n4. Выйти\n>>> ";
		std::cin >> op;
		switch(op) {
			case 1:
				std::cout << "Введите значение\n>>> ";
				std::cin >> val;
				ads.push(val);
				break;
			case 2:
				std::cout << ads.pop() << "\n";
				break;
			case 3:
				seq = inputSequence<T, PATypes::MutableArraySequence<T>>();
				idx = ads.findSequence(seq);
				outputSequence<int>(idx);
				std::cout << "\n";
				delete idx;
				delete seq;
				break;
			case 4:
				exit(0);
				break;
		}
	}
}

template<class T>
void deque() {
	PATypes::Deque<T> deque;
	int op;
	PATypes::Sequence<T> *seq;
	PATypes::Sequence<int> *idx;
	T val;
	while(true) {
		std::cout << "1. Вставить\n2. Убрать\n3. Найти подпоследовательность\n4. Выйти\n>>> ";
		std::cin >> op;
		switch(op) {
			case 1:
				std::cout << "1. В начало\n2. В конец\n>>> ";
				std::cin >> op;
				std::cout << "Введите значение\n>>> ";
				std::cin >> val;
				switch(op) {
					case 1:
						deque.push_front(val);
						break;
					case 2:
						deque.push_back(val);
						break;
				}
				break;
			case 2:
				std::cout << "1. Из начала\n2. Из конца\n>>> ";
				std::cin >> op;
				switch(op) {
					case 1:
						std::cout << deque.pop_front() << "\n";
						break;
					case 2:
						std::cout << deque.pop_back() << "\n";
						break;
				}
				break;
			case 3:
				seq = inputSequence<T, PATypes::MutableArraySequence<T>>();
				idx = deque.findSequence(seq);
				outputSequence<int>(idx);
				std::cout << "\n";
				delete idx;
				delete seq;
				break;
			case 4:
				exit(0);
				break;
		}
	}
}


void stackString() {

}

void stackStudents() {

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
			case 1:
				switch(promptADT()) {
					case 1:
						switch(promptType()) {
							case 1:
								ads<int, PATypes::Stack<int>>();
								break;
							case 2:
								ads<double, PATypes::Stack<double>>();
								break;
							case 3:
								ads<std::complex<double>, PATypes::Stack<std::complex<double>>>();
								break;
							case 4:
								ads<Person, PATypes::Stack<Person>>();
								break;
							case 5:
								ads<Person, PATypes::Stack<Person>>();
								break;
						}
						break;
					case 2:
						switch(promptType()) {
							case 1:
								ads<int, PATypes::Queue<int>>();
								break;
							case 2:
								ads<double, PATypes::Queue<double>>();
								break;
							case 3:
								ads<std::complex<double>, PATypes::Queue<std::complex<double>>>();
								break;
							case 4:
								ads<Person, PATypes::Queue<Person>>();
								break;
							case 5:
								ads<Person, PATypes::Queue<Person>>();
								break;
						}
						break;
					case 3:
						switch(promptType()) {
							case 1:
								deque<int>();
								break;
							case 2:
								deque<double>();
								break;
							case 3:
								deque<std::complex<double>>();
								break;
							case 4:
								deque<Person>();
								break;
							case 5:
								deque<Person>();
								break;
						}
						break;
				}
				break;
			case 2:
				hanoiTowers();
				break;
			case 3:
				running = false;
				break;
		}
	}
	return 0;
}