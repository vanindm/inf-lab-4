#include <iostream>
#include "hanoiTowers.h"

int main() {
		class Green : public IColor {
	public:
		Green() {}
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
		virtual ~HanoiItem() {};
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

	int cnt = 5;

	PATypes::MutableArraySequence<IHanoiItem *> items;

	for (int i = 0; i < cnt; ++i) {
		char c = 'G';
		int area = 6 - i;
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
	int src = 1, dst = 3;
	HanoiTower hanoiTower((PATypes::Sequence<IHanoiItem *> *)&items, src, dst);
	hanoiTower.solve();
	while(cleanup.getLength()) {
		delete cleanup.pop();
	}
	std::cout << "SUCCESS" << std::endl;
	return 0;
}