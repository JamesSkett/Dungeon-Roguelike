#pragma once
#include <string>
#include <vector>

using namespace std;

class MainMenu
{
public:
	MainMenu();

	void displayMenu();

	void loadInstructions(string fileName);
	void printInstructions();

private:
	//stores the instructons data
	vector <string> _instructionsData;
};

