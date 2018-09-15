#include "Cart.h"
#include <iostream>
#include <iomanip>
#include"exception.h"
using namespace std;

int Cart::max_item;
int Cart::total;
Cart::Cart() {
	max_item = 50;
	shopping_cart = { 0 };
	quantityItem = { 0 };
}

Cart::Cart(int size) { //Constructor with a size parameter
	max_item = size;
	shopping_cart = new Item*[max_item];
	quantityItem = new int[max_item];
}

Cart::~Cart() { //Destructor
	delete[] shopping_cart;
	shopping_cart = nullptr;
	delete[] quantityItem;
	quantityItem = nullptr;
}

void Cart::printCart() {
	double totalPrice = 0;
	int b = 0, count = 0;
	cout << endl;
	for (int w = 0; w < max_item; w++) {
		if (shopping_cart[w]->getName() != "")
			count++;
	}
	while (b < count) {
		shopping_cart[b]->print();
		cout << "Quantity: " << quantityItem[b];
		totalPrice += (shopping_cart[b]->getPrice() * quantityItem[b]);
		cout << "Total price: $" << totalPrice << endl << endl;
		b++;
	}
}
void Cart::addItem(Item *nameofitem, int numitems) {
	int duplicateItem = 0; //For the for loop 	

	try {
		for (int i = 0; i < total; i++) {
			if (shopping_cart[i]->getName() == nameofitem->getName()) {
				cout << shopping_cart[i]->getName() << endl;
				quantityItem[i] += numitems;
				duplicateItem = 1;
			}
		}

		if ((total >= max_item)) {

			throw FullCartException(nameofitem->getName());
		}

		/*max_item is size of the cart (5)
		quantityItem[i] is the quantity of item[i]*/
		if (duplicateItem == 0) {
			shopping_cart[total] = nameofitem;
			quantityItem[total] = numitems;
			total++;
		}
	}

	catch (FullCartException e) {
		cout << "Error: can not add " << e.iname << " to cart. Cart is full";
	}

}

void Cart::removeItem(Item *keyItem)
{
	int q = 0; //for the for loop & for cleaning up the cart after item is removed
	int checker = 0;
	//for loop checks if item is present in cart and if so, will remove it
	try {
		for (q = 0; q < max_item; q++) {

			if (keyItem->getName() == shopping_cart[q]->getName()) {
				int move = q;
				if (q == (max_item - 1)) { //if i=4, nothing has to be moved 0-1-2-3-4 = 0-1-2-3
					shopping_cart[max_item - 1]->setPrice(0);
					shopping_cart[max_item - 1]->setName("");
					quantityItem[max_item - 1] = 0;
				}
				else if (q != (max_item - 1))//Have to move each items in the cart down by 1 if i doesn't = 4
				{
					while (move < max_item - 1) {
						//While(2<4) item[2](ball)=item[3](pencil)
						shopping_cart[move]->setName(shopping_cart[move + 1]->getName());
						shopping_cart[move]->setPrice(shopping_cart[move + 1]->getPrice());
						quantityItem[move] = quantityItem[move + 1];//while(3<4) item[3](pencil)=item[4](ruler)
						move++;
					}
					shopping_cart[move]->setPrice(0);
					shopping_cart[move]->setName("");
					quantityItem[move] = 0;
				}

			}

			//couldn't find that item in the cart
			else if (q == max_item)
				throw ItemNotInCartException(keyItem->getName());
		}
	}
	catch (ItemNotInCartException e) {
		cout << "Error: cannot decrease price of " << e.itname << " from cart. Item not in cart.";
	}
}

void Cart::increasePrice(Item *nameofitem, double priceinc)
{
	int check = 0;
	try {
		(nameofitem->setPrice(nameofitem->getPrice() + priceinc));
		for (int e = 0; e < max_item; e++) {
			if (nameofitem->getName() == shopping_cart[e]->getName()) {
				double temp = nameofitem->getPrice();
				if (temp < 0) {
					shopping_cart[e]->setPrice(nameofitem->getPrice()); //setting to old price
					throw NegativePriceException(priceinc);
				}
				else {

					shopping_cart[e]->setPrice(nameofitem->getPrice() + priceinc); //setting to old price + increase
				}
			}
			else if (nameofitem->getName() != shopping_cart[e]->getName())
				check = 1;
			if (check == 1 && e == max_item) {
				throw ItemNotInCartException(nameofitem->getName());
			}
		}
	}
	catch (NegativePriceException e) {
		cout << "Error: cannot subtract " << e.pricech << " from price, because the result is less than 0.";
	}
	catch (ItemNotInCartException e) {
		cout << "Error: cannot decrease price of " << e.itname << " from cart. Item not in cart.";
	}
}

void Cart::decreasePrice(Item *nameofitem, double pricedec)
{
	int check = 0;
	try {
		for (int e = 0; e < max_item; e++) {
			if (nameofitem->getName() == shopping_cart[e]->getName()) {
				if ((nameofitem->getPrice() - pricedec) < 0) {
					shopping_cart[e]->setPrice(nameofitem->getPrice()); //setting to old price
					throw NegativePriceException(pricedec);
				}
				else {
					shopping_cart[e]->setPrice(nameofitem->getPrice() - pricedec); //setting to old price - decrease
				}
			}
			else if (nameofitem->getName() != shopping_cart[e]->getName())
				check = 1;
			if (check == 1 && e == max_item) {
				throw ItemNotInCartException(nameofitem->getName());
			}
		}
	}
	catch (NegativePriceException e) {
		cout << "Error: cannot subtract " << e.pricech << " from price, because the result is less than 0.";
		return;
	}
	catch (ItemNotInCartException e) {
		cout << "Error: cannot decrease price of " << e.itname << " from cart. Item not in cart.";
	}

}
