#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

#include "MainMenu.h"
#include "GameSystem.h"
#include "Renderer.h"

using namespace std;

int main()
{	
	GameSystem* renderer = new GameSystem("level_1.txt");

	renderer->playGame();

	delete renderer;

	return 0;
}