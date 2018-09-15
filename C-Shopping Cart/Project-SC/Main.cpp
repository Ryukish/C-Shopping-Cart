//Problem with how operators working 
//How exception handling is working
//Make stuff of an abstract class

#include<iostream>
#include<string>
#include<stdexcept>
#include<iomanip>
#include"Item.h"
#include"Computer.h"
#include"Produce.h"
#include"Clothing.h"
#include"Cart.h"
#include"exception.h"


using namespace std;




int main()
{

	int ITEMLIST_SIZE = 4;
	int cartSize = 0, i = 0;
	double price[] = { 10, 10.7, 14.5, 22.1 };
	// populating the inventory: itemList
	Item **itemList = new Item*[ITEMLIST_SIZE];

	Produce produce;
	produce.setName("apple");
	produce.setPrice(price[0]);
	produce.setWeight(1.2);
	produce.setExpDate("10/20/18");

	Computer comp1;
	comp1.setName("dell");
	comp1.setPrice(price[1]);
	comp1.setModel("XPS13");
	comp1.setYear(2017);

	Clothing clothing;
	clothing.setName("shirt");
	clothing.setPrice(price[2]);
	clothing.setSize("Medium");
	clothing.setFabric("Cotton");

	Computer comp2;
	comp2.setName("asus");
	comp2.setPrice(price[3]);
	comp2.setModel("turbo");
	comp2.setYear(2016);

	Item **itemlist = new Item*[ITEMLIST_SIZE];
	itemlist[0] = &produce;
	itemlist[1] = &comp1;
	itemlist[2] = &clothing;
	itemlist[3] = &comp2;


	int itemQuantities[] = { 5, 5, 5, 7 };

	cartSize = 3;

	cout << "Creating a cart of size: " << cartSize << endl;
	Cart cart(cartSize);
	cout << "Adding " << cartSize << " items to the cart" << endl;
	for (i = 0; i<cartSize; i++) {
		cart.addItem(itemList[i], itemQuantities[i]);
	}
	cout << "printing cart " << endl;

	cart.printCart();;

	Clothing *newItem = new Clothing();
	newItem->setName(itemlist[2]->getName());
	newItem->setPrice(price[2]);
	newItem->setSize("Medium");
	newItem->setFabric("Cotton");
	cout << "Adding one item already in the cart " << newItem->getName() << ", with additional quantity: " << itemQuantities[2] << endl;
	cart.addItem(newItem, itemQuantities[2]);


	Computer *newItem1 = new Computer();
	newItem1->setName(itemlist[3]->getName());
	newItem1->setPrice(price[3]);
	newItem1->setModel("turbo");
	newItem1->setYear(2016);
	cout << "Adding new item " << newItem1->getName() << endl;
	cart.addItem(newItem1, itemQuantities[3]);


	cout << "printing cart again" << endl;
	cart.printCart();


	cout << "removing item " << newItem->getName() << endl;
	cart.removeItem(newItem);
	cout << "printing cart again" << endl;
	cart.printCart();


	Computer* changeItem = newItem1;

	changeItem->setName(itemlist[1]->getName());
	changeItem->setPrice(price[1]);
	changeItem->setModel("XPS13");
	changeItem->setYear(2017);
	double priceIncrease = 2.99;
	cout << "increasing item " << itemlist[1]->getName() << " old price: " << price[1] << " price increase:" << priceIncrease << endl;
	cart.increasePrice(changeItem, priceIncrease);
	cout << "printing cart with changed price" << endl;
	cart.printCart();

	changeItem->setPrice(itemlist[1]->getPrice());
	double priceDecrease = 1.99;
	cout << "decreasing item " << itemlist[1]->getName() << " old price: " << itemlist[1]->getPrice() << " price decrease:" << priceDecrease << endl;
	cart.decreasePrice(changeItem, priceDecrease);
	cout << "printing cart with changed price" << endl;
	cart.printCart();


	return 0;

}









