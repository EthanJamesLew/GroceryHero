#ifndef MAIN_CONSOLE_H
#define MAIN_CONSOLE_H
#include <string>
#include "grocery.h"
#include "main_control.h"

/*
Main console is the main text renderer for the application. It handles text
input and sends it to the Main_Control
*/
class Main_Console
{
public:
	Main_Console();
	~Main_Console();
	void clearConsole();
	void renderMain();
	void mainLoop();
	void setGrocery(Grocery* grocery);

private:
	Grocery* _grocery;
	Main_Control* _control;
	char* _command;
};
#endif
