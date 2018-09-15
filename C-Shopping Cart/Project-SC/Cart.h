#ifndef Cart_hpp
#define Cart_hpp
#include "Item.h"
#include "Computer.h"
#include "Produce.h"

using namespace std;

class Cart {
	static int max_item;
	Item **shopping_cart;
	int *quantityItem;
	static int total;

public:
	Cart();
	Cart(int size);
	~Cart();
	void addItem(Item *nameofitem, int numitems);
	void removeItem(Item *keyItem);
	void increasePrice(Item *nameofitem, double priceinc);
	void decreasePrice(Item *nameofitem, double pricedec);
	void printCart();
};


#endif