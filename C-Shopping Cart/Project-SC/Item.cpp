#include "Item.h"

using namespace std;
Item::Item() {
	string name = "";
	double price = 0;
}
void Item::setName(string iname) {
	name = iname;
}

void Item::setPrice(double iprice) {
	price = iprice;
}
string Item::getName() {
	return name;
}
double Item::getPrice() {
	return price;
}
