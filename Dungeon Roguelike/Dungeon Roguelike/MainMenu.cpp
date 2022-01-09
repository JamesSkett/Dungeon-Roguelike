#include "MainMenu.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>

using namespace std;

MainMenu::MainMenu()
{

}

//---------------------------------------------------------------------------------------------------
void MainMenu::displayMenu()
{
	system("CLS");
	char menuInput;

	//main menu contents
	printf("                    -- Dungeon Escape --\n\n");
	printf("                         MAIN MENU\n\n");
	printf("                     1. Play Game\n");
	printf("                     2. Instructions\n");
	printf("                     3. Exit Game\n\n\n\n\n\n\n");
	printf("              Select Menu Option (1 / 2 / 3): ");

	//stored player input in menu input variable
	menuInput = _getch();

	//process menu input
	switch (menuInput)
	{
	case 49: //49 is the ASCII value of '1' removes error when a character is entered
		//no action needed just returns back to gamesystem
		break;
	case 50: //50 is the ASCII value of '2'
		//load then display instructions
		loadInstructions("Instructions.txt");
		printInstructions();
		_getch();
		printf("%s", string(100, '\n').c_str());
		//returns to main menu when player presses enter
		return displayMenu();
		break;
	case 51: //51 is the ASCII value of '3'
		//close the game
		exit(1);
		break;
	default:
		//anything not one of the above then invalid input
		printf("Invalid input please enter 1, 2, or 3");
		return displayMenu();
		break;
	}
}

//---------------------------------------------------------------------------------------------------
void MainMenu::loadInstructions(string fileName)
{
	//Loads the  instuctions
	ifstream file;

	//Open the file and quit if it fails to open
	file.open(fileName);
	if (file.fail())
	{
		perror(fileName.c_str());
		printf("Press any key to continue:");
		_getch();
		exit(1);
	}

	string line;

	//Loop through the entire file, getting each row and
	//putting it in the line string.
	while (getline(file, line))
	{
		//Push the current line onto the _instructionsData array
		_instructionsData.push_back(line);
	}

	file.close();
}

//---------------------------------------------------------------------------------------------------
//prints out the instructions stored in a vector of strings
void MainMenu::printInstructions()
{
	//pads the screen with newlines so previous text cant be seen
	printf("%s", string(100, '\n').c_str());

	for (int i = 0; i < _instructionsData.size(); i++) {
		printf("%s\n", _instructionsData[i].c_str());
	}
}
