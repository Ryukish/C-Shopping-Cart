#ifndef Clothing_cpp
#define Clothing_cpp

#include "Item.h"

using namespace std;

class Clothing :public Item {
	string size;
	string fabric;

public:
	void setSize(string isize);
	void setFabric(string ifabric);
	string getSize();
	string getFabric();
	Clothing();
	void print();
	double operator+(double rhs);
	double operator-(double rhs);
};

#endif