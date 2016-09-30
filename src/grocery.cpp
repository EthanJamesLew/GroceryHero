#include "grocery.h"
#include <iostream>

void remove_element(Grocery_Item *array, int index, int array_length)
{
	int i;
	for (i = index; i < array_length - 1; i++) array[i] = array[i + 1];
}

Grocery::Grocery() : _size(0)
{
	_items = new Grocery_Item();
}


Grocery::~Grocery()
{
	delete _items;
}

void Grocery::addItem(char* name, double price, int quantity)
{
	_items[_size] = Grocery_Item(name, price, quantity);	
	_size++;
}


void Grocery::printItems()
{
	for (int i = 0; i < _size; i++)
	{
		std::cout << _items[i] << std::endl;
	}
	
}

void Grocery::deleteItem(char* name)
{
	for (int i = 0; i < _size; i++)
	{
		if (!strcmp(_items[i].name, name))
		{
			remove_element(_items, i, _size);
			_size -= 1;
			return;
		}
	}
}

void Grocery::editItem(char* name, double price, int quantity)
{
	for (int i = 0; i < _size; i++)
	{
		if (!strcmp(_items[i].name, name))
		{
			_items[i].price = price;
			_items[i].quantity = quantity;
		}
	}
}

double Grocery::getTotal()
{
	double total = 0.0;
	for (int i = 0; i < _size; i++)
	{
		total += _items[i].quantity * _items[i].price;
	}
	return total;
}

bool Grocery::isItem(char* name)
{
	for (int i = 0; i < _size; i++)
	{
		if (!strcmp(_items[i].name, name))
		{
			return true;
		}
	}
	return false;
}
