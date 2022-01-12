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
	GameSystem* renderer = new GameSystem("hahahah");

	renderer->playGame();

	return 0;
}