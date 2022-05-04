#include <iostream>
#include <cstdlib>
#include <string>
//#include <conio.h>

#include "MainMenu.h"
#include "GameSystem.h"
#include "Renderer.h"
#include "Engine.h"

using namespace std;

int main()
{	
	engine::PrintMessage();
	GameSystem* renderer = new GameSystem("level_1.txt");

	renderer->playGame();

	delete renderer;

	return 0;
}