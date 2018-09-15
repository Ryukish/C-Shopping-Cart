#include<iostream>
#include"Produce.h"
#include <iomanip>

using namespace std;

Produce::Produce() {
	double weight = 0;
	string expDate = "";
}
void Produce::setExpDate(string iExpDate) {
	expDate = iExpDate;
}
void Produce::setWeight(double iWeight) {
	weight = iWeight;
}
string Produce::getExpDate() {
	return expDate;
}
double Produce::getweight() {
	return weight;
}
void Produce::print() {
	cout << "Product name: " << name << endl;
	cout << fixed;
	cout << "Price: $" << setprecision(2) << price << endl;
	cout << "Weight: " << weight << " Kg" << endl;
	cout << "Expiration date: " << expDate << endl;
}