#include "GameSystem.h"
#include "Engine.h"
#include <iostream>

int main()
{	
	engine::Vector2 v1 = { 2 ,4 };
	engine::Vector2 v2 = { 5, 9 };

	std::cout << engine::DotProduct(v1, v2) << std::endl;

	GameSystem* renderer = new GameSystem("level_1.txt");

	renderer->playGame();

	delete renderer;

	return 0;
}