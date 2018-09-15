#ifndef Item_h
#define Item_h

#include <stdio.h>
#include <string>
using namespace std;


class Item {
protected:
	string name;
	double price;

public:
	Item();
	virtual void print() = 0;
	void setName(string iname);
	void setPrice(double iprice);
	string getName();
	double getPrice();
};

#endif