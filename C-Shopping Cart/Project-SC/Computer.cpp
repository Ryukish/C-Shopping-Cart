#include "Computer.h"
#include <iomanip>
#include<iostream>
using namespace std;

Computer::Computer() {
	string model = "";
	int makeYear = 0;
}
void Computer::setModel(string imodel) {
	model = imodel;
}
void Computer::setYear(int year) {
	makeYear = year;
}
string Computer::getModel() {
	return model;
}
double Computer::getYear() {
	return makeYear;
}
void Computer::print() {
	cout << "Product name: " << name << endl;
	cout << fixed;
	cout << "Price: $" << setprecision(2) << price << endl;
	cout << "Model: " << model << "Kg" << endl;
	cout << "Year: " << makeYear << endl;
}

Computer Computer::operator+(double rhs) {
	Computer tempsumi;
	tempsumi.price = price + rhs;
	return tempsumi;
}
Computer Computer::operator-(double rhs) {
	Computer tempsumd;
	tempsumd.price = price + rhs;
	return tempsumd;
}