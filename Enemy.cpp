#include "Enemy.h"
#include <cmath>
#include "time.h"
#include <random>
#include <ctime>

//constructor initialises the enemy
Enemy::Enemy(char tile)
{
	_tile = tile;
}

//------------------------------------------------------------------------------------------------------
//this does the enemy AI
char Enemy::getMove(int playerX, int playerY)
{
	int distanceFromPlayer;

	//get the distance from the player to decide if we should move towards hi or just move around randomly
	int distanceX = _x - playerX;
	int distanceY = _y - playerY;
	int absoluteDX = abs(distanceX);
	int absoluteDY = abs(distanceY);

	distanceFromPlayer = absoluteDX - absoluteDY;

	//If the distance is closer than 6 tiles, then move towards the  player
	if (distanceFromPlayer <= 5)
	{
		//Move along the x axis
		if (absoluteDX > absoluteDY)
		{
			if (distanceX > 0) //if player is left, move left. Otherwise move right
			{
				return 'a';
			}
			else 
			{
				return 'd';
			}
		}
		else //move along y axis
		{
			if (distanceY > 0)
			{
				return 'w';
			}
			else
			{
				return 's';
			}
		}
	}

	//generates random number
	srand(time(NULL));
	int randomMove =  rand() % 4;

	switch (randomMove)
	{
	case 0: //up
		return 'w';
		break;
	case 1: //down
		return 's';
		break;
	case 2: //left
		return 'a';
		break;
	case 3: //right
		return 'd';
		break;
	default: //no movement
		return '.';
		break;
	}

	
		return 0;
}