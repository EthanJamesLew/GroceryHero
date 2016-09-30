#include "main_console.h"
#include <fstream>
#include <iostream>
#include <cstring>

#define COMMAND_LEN 256

Main_Console::Main_Console()
{
	_command = new char[COMMAND_LEN];
	_control = new Main_Control();
	_control->setGrocery(_grocery);
}

Main_Console::~Main_Console()
{
	delete _grocery;
}

void Main_Console::clearConsole()
{

}

void Main_Console::renderMain()
{
	std::ifstream infile1;
	infile1.open("./text/menu.txt");

	if (infile1.fail())
	{
		std::cout << "File failed to open.\n";
		exit(1);
	}

	do{std::cout << (char)infile1.get();}while ((infile1.good()));
}

void Main_Console::setGrocery(Grocery* grocery)
{
	_grocery = grocery;
	_control->setGrocery(grocery);
}

void Main_Console::mainLoop()
{
	//Receives string and checks if quit command
	//If not, it pushes it to controller class
	while (true)
	{
		std::cout << "\ngrocery >";
		std::cin.getline(_command, 1000);
		if (!strcmp(_command, "exit") | !strcmp(_command, "quit") | !strcmp(_command, "q") | !strcmp(_command, "break")) break;
		_control->execCommand(_command);
	}
}
