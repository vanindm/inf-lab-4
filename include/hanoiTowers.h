#include <iostream>

#include "PATypes/Stack.h"



class IColor {
	public:
		virtual int getColor() = 0;
		virtual char getRepresentation() = 0;
};

class IHanoiItem {
	public:
		virtual bool compare(IHanoiItem* other) = 0;
		virtual IColor getColor() = 0;
};

class HanoiTower {
	PATypes::Stack<IHanoiItem*> pile1;
	PATypes::Stack<IHanoiItem*> pile2;
	PATypes::Stack<IHanoiItem*> pile3;
public:

};