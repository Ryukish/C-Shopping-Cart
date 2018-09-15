#ifndef Computer_hpp
#define Computer_hpp

#include "Item.h"

using namespace std;

class Computer :public Item {
	string model;
	int makeYear;

public:
	void setModel(string model);
	void setYear(int year);
	string getModel();
	double getYear();
	Computer();
	void print();
	Computer operator+(double rhs);
	Computer operator-(double rhs);
};

#endif