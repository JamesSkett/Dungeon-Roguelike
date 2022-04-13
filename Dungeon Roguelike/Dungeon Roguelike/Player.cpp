#include "Player.h"
#include <iostream>	
#include <conio.h>
#include <cstdlib>

#include "Image.h"


Player::Player(float x, float y, const char* filePath)
{
	//initialises the players x and y coords to 0
	_x = x;
	_y = y;

	m_image = new Image(_x, _y, filePath);
}

void Player::Draw()
{
	m_image->Draw();
}

Image* &Player::GetImage() 
{
	return m_image;
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

