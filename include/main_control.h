#ifndef MAIN_CONTROL_H
#define MAIN_CONTROL_H
#include "grocery.h"
/*
Main_Control is responsible for processing user input and editing the Grocery
model
*/
class Main_Control
{
public:
	Main_Control(){}
	void setGrocery(Grocery* grocery);
	void execCommand(char* command);

private:
	bool _check(char* name);
	void _processTrigger(char* ops, void(*f)(char*, double, int));
	void _ls();
	void _add(char* name, double price, int quantity=1);
	void _edit(char* name, double price, int quantity=1);
	void _delete(char* name);
	Grocery* _grocery;
};
#endif
