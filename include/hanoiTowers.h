#include <iostream>

#include "PATypes/Stack.h"
#include "PATypes/Sequence.h"
#include "PATypes/IEnumerator.h"

class IColor {
	public:
		virtual int getColor() = 0;
		virtual char getRepresentation() = 0;
};

class IHanoiItem {
	public:
		virtual bool compare(IHanoiItem* other) = 0;
		virtual int getArea() = 0;
		virtual IColor* getColor() = 0;
};

class HanoiTower {
	PATypes::Stack<IHanoiItem*> pile1;
	PATypes::Stack<IHanoiItem*> pile2;
	PATypes::Stack<IHanoiItem*> pile3;
	PATypes::Stack<IHanoiItem*> *_src;
	PATypes::Stack<IHanoiItem*> *_dst;
	PATypes::Stack<IHanoiItem*> *_ind;
public:
	HanoiTower(PATypes::Sequence<IHanoiItem*> *items, int src, int dst) {
		switch (src) {
			case 1:
				_src = &pile1;
				break;
			case 2:
				_src = &pile2;
				break;
			case 3:
				_src = &pile3;
				break;
		}
		switch (dst) {
			case 1:
				_dst = &pile1;
				_ind = (_src == &pile2 ? &pile3 : &pile2);				
				break;
			case 2:
				_dst = &pile2;
				_ind = (_src == &pile1 ? &pile3 : &pile1);				
				break;
			case 3:
				_dst = &pile3;
				_ind = (_src == &pile2 ? &pile1 : &pile2);				
				break;
		}
		_src->push(items->getFirst());
		PATypes::IEnumerator<IHanoiItem *> *enumerator;
		for (enumerator = items->getEnumerator(); enumerator->moveNext();) {
			_src->push(enumerator->current());
		}
		delete enumerator;
	}
	void solve() {
		solve(_src->getLength(), _src, _dst, _ind);
	}
	void solve(int n, PATypes::Stack<IHanoiItem*> *src, PATypes::Stack<IHanoiItem*> *dst, PATypes::Stack<IHanoiItem*> *ind) {
		IHanoiItem* current;
		if (n == 1) {
			current = src->pop();
			if (dst->getLength() && current->compare(dst->getLast())) {
				throw std::logic_error("попытка поставить диск больше на диск меньше");
			}
			dst->push(current);
		} else {
			solve(n - 1, src, ind, dst);
			current = src->pop();
			if (dst->getLength() && current->compare(dst->getLast())) {
				throw std::logic_error("попытка поставить диск больше на диск меньше");
			}
			dst->push(current);
			solve(n - 1, ind, dst, src);
		}
	}
};