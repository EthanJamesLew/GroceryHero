#ifndef GROCERY_H
#define GROCERY_H
#include "grocery_item.h"
/*
Grocery models a shopping list. It handles an array of grocery items.
*/
class Grocery
{
public:
	Grocery();
	~Grocery();

	void printItems();
	void addItem(char* name, double price, int quantity);
	void deleteItem(char* name);
	void editItem(char* name, double price, int quantity);
	double getTotal();

	bool isItem(char* name);

private:
	Grocery_Item* _items;
	int _size;
};
#endif
