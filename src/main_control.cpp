#include "main_control.h"
#include <iostream>
#include <cstring>

#define NAME_LEN 64

int split(char *str, char *arr[10]){
	int beginIndex = 0;
	int endIndex;
	int maxWords = 10;
	int wordCnt = 0;

	while (true){
		while (isspace(str[beginIndex])){
			++beginIndex;
		}
		if (str[beginIndex] == '\0')
			break;
		endIndex = beginIndex;
		while (str[endIndex] && !isspace(str[endIndex])){
			++endIndex;
		}
		int len = endIndex - beginIndex;
		char *tmp = (char*)calloc(len + 1, sizeof(char));
		memcpy(tmp, &str[beginIndex], len);
		arr[wordCnt++] = tmp;
		beginIndex = endIndex;
		if (wordCnt == maxWords)
			break;
	}
	return wordCnt;
}

int isnumber(const char *s)
{
	char *ep = NULL;
	double f = strtod(s, &ep);
	f++;

	if (!ep || *ep)
		return false;  // has non-floating digits after number, if any

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
	int quantity = 1;

	char* argv[10];

	int argc = split(command, argv);

	strcpy(command_name, argv[0]);
	strcpy(name,argv[1]);
	for (int i = 2; i < argc; ++i)
	{
		if (!strcmp(argv[i], "-q") && i != argc - 1) quantity = atoi(argv[i + 1]);
		if (isnumber(argv[i]) && strcmp(argv[i - 1], "-q")) price = atof(argv[i]);

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

void Main_Control::_add(char* name, double price, int quantity)
{
	if (!_check(name)) { std::cout << name << " already exists!"<<std::endl; return; }
	_grocery->addItem(name, price, quantity);
	std::cout.precision(2);
	std::cout << std::fixed << "Added item " << name << ". Your current total is $" << _grocery->getTotal() << std::endl;
}

void Main_Control::_edit(char* name, double price, int quantity)
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
