#include "Player.h"
#include <iostream>	
#include <conio.h>
#include <cstdlib>

#include "Image.h"
#include "Tile.h"

Player::Player(float x, float y, const char* filePath)
	: Entity(x, y, filePath), _energyBars(0), _lives(3), _spades(0)
{

}

void Player::UpdatePosition(float dx, float dy, const std::vector<Tile*> &vTiles)
{
	float oldXPos = GetImage()->GetXPos();
	float oldYPos = GetImage()->GetYPos();

	GetImage()->UpdatePosition(dx, dy);

	if (OnCollision(vTiles))
		GetImage()->SetPos(oldXPos, oldYPos);
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
}

//---------------------------------------------------------------------------------------------------
//used to check if the player has a spade to dig with in Level::movePlayer() function
bool Player::hasSpade()
{
	return _spades ? false : true;
}

//---------------------------------------------------------------------------------------------------
//adds a spade when player walks over spade pickup
void Player::addSpade()
{
	printf("\nYou Picked up a spade.\n");
	printf("Press any key to continue: ");
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
	_energyBars++;
}

bool Player::OnCollision(const std::vector<Tile*> &vTiles)
{
	for (int i = 0; i < vTiles.size(); i++)
	{
		if (vTiles[i]->IsWalkable() == false)
		{
			float tileX = vTiles[i]->GetImage()->GetXPos();
			float tileY = vTiles[i]->GetImage()->GetYPos();
			int tileW = vTiles[i]->GetImage()->GetWidth();
			int tileH = vTiles[i]->GetImage()->GetHeight();
			if ((GetImage()->GetXPos() < tileX + tileW) && (GetImage()->GetXPos() + GetImage()->GetWidth() > tileX) &&
				(GetImage()->GetYPos() < tileY + tileH) && (GetImage()->GetYPos() + GetImage()->GetHeight() > tileY))
			{
				return true;
			}
		}
	}

	return false;
}

