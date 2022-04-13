#include "Player.h"
#include <iostream>	
#include <conio.h>
#include <cstdlib>

#include "Image.h"
#include "Tile.h"

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

void Player::UpdatePosition(float dx, float dy, std::vector<Tile*> &vTiles)
{
	float oldXPos = m_image->GetXPos();
	float oldYPos = m_image->GetYPos();

	m_image->UpdatePosition(dx, dy);

	if (OnCollision(vTiles))
		m_image->SetPos(oldXPos, oldYPos);
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

bool Player::OnCollision(std::vector<Tile*> &vTiles)
{
	for (int i = 0; i < vTiles.size(); i++)
	{
		if (vTiles[i]->IsWalkable() == false)
		{
			float tileX = vTiles[i]->GetImage()->GetXPos();
			float tileY = vTiles[i]->GetImage()->GetYPos();
			int tileW = vTiles[i]->GetImage()->GetWidth();
			int tileH = vTiles[i]->GetImage()->GetHeight();
			if ((m_image->GetXPos() < tileX + tileW) && (m_image->GetXPos() + m_image->GetWidth() > tileX) &&
				(m_image->GetYPos() < tileY + tileH) && (m_image->GetYPos() + m_image->GetHeight() > tileY))
			{
				return true;
			}
		}
	}

	return false;
}

