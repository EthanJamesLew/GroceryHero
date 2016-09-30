#ifndef GROCERY_ITEM_H
#define GROCERY_ITEM_H
#include <cstring>
#include <iomanip>
#include <sstream>

#define NAME_LEN 64

/*
	Grocery_Item models an item on a shopping list
*/
struct Grocery_Item
{

	char name[NAME_LEN];
	double price;
	int quantity;

	Grocery_Item(char* na, double price, int quantity) : price(price), quantity(quantity){ strcpy(name,na); }

	Grocery_Item(){ }

	void setName(char* na){ strcpy(name, na); }
	void setValue(double pri){ price = pri; }
	void setQuantity(int quant){ quantity = quant; }

	friend std::ostream & operator << (std::ostream &os, Grocery_Item it)
	{
		os.precision(2);
		os << it.name << "	$" <<std::fixed<< it.price << "	#" << it.quantity;
		return os;
	}
};
#endif
