#pragma once

class Player
{
public:
	Player();
	void init(int lives, int energyBars, int spades);

	void printProperties();
	void removeLives();
	bool hasSpade();
	void addSpade();
	void removeSpade();
	void addEnergyBar();


	//Setters
	void setPosition(int x, int y);
	//Getters
	void getPosition(int &x, int &y);

	//properties
	int _energyBars;
	int _lives;
private:
	int _spades;


protected:
	//Position
	int _x;
	int _y;

};

