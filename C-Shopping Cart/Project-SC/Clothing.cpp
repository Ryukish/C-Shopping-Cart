#include "Clothing.h"
#include <iostream>
#include <iomanip>

using namespace std;

Clothing::Clothing() {
	string size = "";
	string fabric = "";
}
void Clothing::setSize(string isize) {
	size = isize;
}
void Clothing::setFabric(string ifabric) {
	fabric = ifabric;
}
string Clothing::getSize() {
	return size;
}
string Clothing::getFabric() {
	return fabric;
}
void Clothing::print() {
	cout << "Product name: " << name << endl;
	cout << fixed;
	cout << "Price: $" << setprecision(2) << price << endl;
	cout << "Size: " << size << endl;
	cout << "Fabric: " << fabric << endl;
}
double Clothing::operator+(double rhs) {
	Clothing tempsumi;
	tempsumi.price = price + rhs;
	return tempsumi.price;
}
double Clothing::operator-(double rhs) {
	Clothing tempsumd;
	tempsumd.price = price + rhs;
	return tempsumd.price;
}