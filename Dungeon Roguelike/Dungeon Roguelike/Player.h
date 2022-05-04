#pragma once
#include <vector>

#include "Entity.h"

class Image;
class Tile;

class Player : public Entity
{
public:
	Player(float x, float y, const char* filePath);

	void UpdatePosition(float dx, float dy, const std::vector<Tile*> &vTiles);

	void init(int lives, int energyBars, int spades);

	void printProperties();
	void removeLives();
	bool hasSpade();
	void addSpade();
	void removeSpade();
	void addEnergyBar();

	bool OnCollision(const std::vector<Tile*> &vTiles);

	//properties

private:

	int _energyBars = 0;
	int _lives = 0;
	int _spades = 0;

};

