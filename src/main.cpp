//Ethan Lew
//G03729047
//10/03/2016
//CS 162
//Project 1
//CS 162
//Instructor Li Liang

#include "main_console.h"
#include <iostream>

int main(int argc, char* argv[])
{
	/*
		Main creates a text render context and points it to a grocery data model.
		The command prompt is started by mainLoop. 
	*/
	Grocery* groc = new Grocery();
	Main_Console main;
	main.renderMain();
	main.setGrocery(groc);
	main.mainLoop();

	return 0;
}
