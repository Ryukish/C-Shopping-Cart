#ifndef exception_h
#define exception_h

#include<stdexcept>

using namespace std;

class NegativePriceException {
public:
	NegativePriceException(double pricede) : pricech(pricede)
	{}
	double pricech;
};
class ItemNotInCartException {
public:
	ItemNotInCartException(string name) :itname(name) {
	}
	string itname;
};
class FullCartException {
public:
	FullCartException(string itemname) : iname(itemname) {}
	string iname;
};

#endif

