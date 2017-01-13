#include "Player.h"
#include <iostream>	
#include <conio.h>
#include <cstdlib>

using namespace std;


Player::Player()
{
	//initialises the players x and y coords to 0
	_x = 0;
	_y = 0;
}

//---------------------------------------------------------------------------------------------------
//initialises the player properties 
void Player::init(int lives, int energyBars, int spades)
{
	_lives = lives;
	_energyBars = energyBars;
	_spades = spades;
}

//---------------------------------------------------------------------------------------------------
//prints the players properties to the screen  
void Player::printProperties()
{
	printf("Energy Bars Reqired: 8 ");
	printf("Lives Left: %d     ", _lives);
	printf("Energy Bars: %d \n", _energyBars);
	printf("Spades: %d", _spades);

}

//---------------------------------------------------------------------------------------------------
//removes a life when the player dies
void Player::removeLives()
{
	printf("\n\nYou Lost a life!\n");
	_lives--;
	_getch();
}

//---------------------------------------------------------------------------------------------------
//used to check if the player has a spade to dig with in Level::movePlayer() function
bool Player::hasSpade()
{
	if (_spades == 0)
	{
		return false;
	}
	else 
	{
		return true;
	}
	
}

//---------------------------------------------------------------------------------------------------
//adds a spade when player walks over spade pickup
void Player::addSpade()
{
	printf("\nYou Picked up a spade.\n");
	printf("Press any key to continue: ");
	_getch();
	_spades++;
}

//---------------------------------------------------------------------------------------------------
//removes a spade when the player digs a hole
void Player::removeSpade()
{
	_spades--;
}

//---------------------------------------------------------------------------------------------------
//adds an energy bar when player walks over 'E' tile
void Player::addEnergyBar()
{
	printf("\nYou gained an Energy Bar! \nPress any key to continue: ");
	_getch();
	_energyBars++;
}

//---------------------------------------------------------------------------------------------------
//sets the players position
void Player::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

//---------------------------------------------------------------------------------------------------
//gets the players position
void Player::getPosition(int &x, int &y)
{
	x = _x;
	y = _y;
}
