#include "main_control.h"
#include <iostream>
#include <cstring>
#include <ios>

#define NAME_LEN 64

int split(char *str, char *arr[10]){
	int startIdx = 0;
	int endIdx;
	int max = 10;
	int count = 0;

	while (true){
		while (isspace(str[startIdx])){
			++startIdx;
		}
		if (str[startIdx] == '\0')
			break;
		endIdx = startIdx;
		while (str[endIdx] && !isspace(str[endIdx])){
			++endIdx;
		}
		int len = endIdx - startIdx;
		char *tmp = (char*)calloc(len + 1, sizeof(char));
		memcpy(tmp, &str[startIdx], len);
		arr[count++] = tmp;
		startIdx = endIdx;
		if (count == max)
			break;
	}
	return count;
}

int isnumber(const char *s)
{
	char *castTest = NULL;
	double f = strtod(s, &castTest);
	f++;

	if (!castTest || *castTest)
		return false; 

	return true;
}

void Main_Control::setGrocery(Grocery* grocery)
{
	_grocery = grocery;
}

void Main_Control::execCommand(char* command)
{
	//TODO: Create a parsing class to handle this
	//This is a terrible hack
	char name[NAME_LEN];
	char command_name[NAME_LEN];
	float price = -1.0;
	float quantity = 1;

	char* argv[10];

	int argc = split(command, argv);

	strcpy(command_name, argv[0]);
	if (argc > 1) strcpy(name,argv[1]);
	for (int i = 2; i < argc; ++i)
	{
		if (!strcmp(argv[i], "-q") && i != argc - 1) quantity = atof(argv[i + 1]);
		else if (isnumber(argv[i]) && strcmp(argv[i - 1], "-q")) price = atof(argv[i]);
		else if (price == -1.0 && strcmp(argv[i-1], "-q")) { strcat(name, " "); strcat(name, argv[i]); }
	}
	//Check inputs
	if (!(!strcmp(command_name, "add") | !strcmp(command_name, "a") | !strcmp(command_name, "edit") | !strcmp(command_name, "e") | !strcmp(command_name, "delete") | !strcmp(command_name, "d") | !strcmp(command_name, "ls") | !strcmp(command_name, "l"))) { std::cout << command_name << " not found." << std::endl; return; }

	if (strcmp(command_name, "ls")&& strcmp(command_name, "l") && strcmp(command_name, "delete") && strcmp(command_name, "d"))
	{
		if (quantity <= 0){ std::cout << "Could not interpret quantity."; return; }
		if (price == -1.0){ std::cout << "Could not find price."; return; }
	}

	if (!strcmp(command_name, "add") | !strcmp(command_name, "a")) _add(name, price, quantity);
	else if (!strcmp(command_name, "edit") | !strcmp(command_name, "e")) _edit(name, price, quantity);
	else if (!strcmp(command_name, "delete") | !strcmp(command_name, "d"))_delete(name);
	else if (!strcmp(command_name, "ls") | !strcmp(command_name, "l"))_ls();
	else std::cout << "Error" << std::endl;

}

void Main_Control::_ls()
{
	_grocery->printItems();
	std::cout.precision(2);
	std::cout << std::fixed << "Your current total is $" << _grocery->getTotal() << std::endl;
}

void Main_Control::_add(char* name, double price, double quantity)
{
	if (!_check(name)) { std::cout << name << " already exists!"<<std::endl; return; }
	_grocery->addItem(name, price, quantity);
	std::cout.setf(ios::fixed, ios::floatfield);
	std::setf(ios::showpoint);
	std::cout.precision(2);
	std::cout << std::fixed << "Added item " << name << ". Your current total is $" << _grocery->getTotal() << std::endl;
}

void Main_Control::_edit(char* name, double price, double quantity)
{
	if (_check(name)){ std::cout <<"Could not find " << name<< std::endl; return; }
	_grocery->editItem(name, price, quantity);
	std::cout << std::fixed<< "Edited item " << name << ". Price set to " << price << " and quantity set to " << quantity << "."<<std::endl;;
}

void Main_Control::_delete(char* name)
{
	if (_check(name)) { std::cout << "Could not find " << name << std::endl; return; }
	_grocery->deleteItem(name);
	std::cout.precision(2);
	std::cout << std::fixed << "Deleted item " << name << ". Your current total is $" << _grocery->getTotal() << std::endl;
}


bool Main_Control::_check(char* name)
{
	return _grocery->isItem(name) ? false: true;

}
