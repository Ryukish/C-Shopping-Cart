#ifndef Produce_cpp
#define Produce_cpp

#include "Item.h"

using namespace std;

class Produce :public Item {
	double weight;
	string expDate;

public:
	void setExpDate(string iExpDate);
	void setWeight(double iWeight);
	string getExpDate();
	double getweight();
	Produce();
	void print();
	double operator+(double rhs);
	double operator-(double rhs);
};

#endif 

