#pragma once
#include <vector>

class Image;
class Tile;

class Player
{
public:
	Player(float x, float y, const char* filePath);

	void Draw();

	Image* &GetImage();

	void UpdatePosition(float dx, float dy, std::vector<Tile*> &vTiles);

	void init(int lives, int energyBars, int spades);

	void printProperties();
	void removeLives();
	bool hasSpade();
	void addSpade();
	void removeSpade();
	void addEnergyBar();

	bool OnCollision(std::vector<Tile*> &vTiles);

	//properties
	int _energyBars = 0;
	int _lives = 0;
private:
	int _spades = 0;
	Image* m_image;


protected:
	//Position
	int _x;
	int _y;

};

