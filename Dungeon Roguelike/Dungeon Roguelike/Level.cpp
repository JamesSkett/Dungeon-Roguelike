#include "Level.h"
#include <fstream>
#include <conio.h>
#include <cstdlib>

#include <allegro5/allegro_native_dialog.h>


#include "Tile.h"
#include "Wall.h"
#include "Floor.h"
#include "Player.h"
#include "Renderer.h"

Level::Level()
{
}

//---------------------------------------------------------------------------
void Level::Load(const char* fileName, std::vector<Tile*> &tiles, Player* &player)   //This loads the level from the file "Level_1.txt"
{
	//Loads the  level
	std::ifstream file;

	//Open the file and quit if it fails to open
	file.open(fileName);
	if (file.fail())
	{
		perror(fileName);

		al_show_native_message_box(Renderer::disp, "Message Box", "Error", "OMG IT DED", NULL, ALLEGRO_MESSAGEBOX_ERROR);

		exit(1);
	}

	std::string line;

	//Loop through the entire file, getting each row and
	//putting it in the line string.
	while (std::getline(file, line)) 
	{
		//Push the current line onto the _levelData array
		m_levelData.push_back(line);
	}

	file.close();

	//Process the Level
	char tile;



	//loops through the _levelData vector and processes each tile
	for (int i = 0; i < m_levelData.size(); i++)
	{
		for (int j = 0; j < m_levelData[i].size(); j++)
		{
			tile = m_levelData[i][j];

			float x = (float)j;
			float y = (float)i;

			switch (tile)
			{
			case '@':
				CreateFloor(x, y, tiles);
				player = new Player(x * m_tileOffset, y * m_tileOffset, "player.png");
				//player.setPosition(j, i);
				break;
			case 'M':
				CreateFloor(x, y, tiles);
				//m_enemy.push_back(Enemy('M'));
				//m_enemy.back().setPosition(j, i);
				break;
			case '#': //All the tiles that dont need extra processing, in this case, walls, air, spade and energy bar
				CreateWall(x, y, tiles);
				break;
			case '.':
				CreateFloor(x, y, tiles);
			case 'S':
				CreateFloor(x, y, tiles);

			case 'E':
				CreateFloor(x, y, tiles);
			case 'B':
				CreateFloor(x, y, tiles);
			case 'X':
				CreateFloor(x, y, tiles);
				//Doesnt need to do anthing, just break.
				break;
			default: //If it gets here, tile hasnt been registered the, so print out a warning
				printf("WARNING: Unknown tile %c at %d,%d", tile, j, i);
				system("Pause");
				break;
			}
		}
	}

}

void Level::CreateFloor(float x, float y, std::vector<Tile*> &tiles)
{
	tiles.push_back(new Floor(x * m_tileOffset, y * m_tileOffset, true, "floor.png"));
}

void Level::CreateWall(float x, float y, std::vector<Tile*>& tiles)
{
	tiles.push_back(new Wall(x * m_tileOffset, y * m_tileOffset, false, "wall.png"));
}

//---------------------------------------------------------------------------
void Level::print() //Prints out the level.
{
	//prints a bunch of new lines so previous level print cant be seen
	printf("%s", std::string(100, '\n').c_str());

	//prints each line of the vector 1 by 1
	for (int i = 0; i < m_levelData.size(); i++) {
		printf("%s\n", m_levelData[i].c_str());
	}

}

//---------------------------------------------------------------------------
void Level::movePlayer(char input, Player &player)
{
	////used to store player position
	//int playerX;
	//int playerY;


	////checks to see if player has a spade or not then stores answer in bool hasSpade
	//bool hasSpade = player.hasSpade();

	////processes the player input
	//switch (input)
	//{
	//case 'w': //up
	//case 'W':
	//	processPlayerMove(player, playerX, playerY - 1);
	//	break;
	//case 's': //down
	//case 'S':
	//	processPlayerMove(player, playerX, playerY + 1);
	//	break;
	//case 'a': //left
	//case 'A':
	//	processPlayerMove(player, playerX - 1, playerY);
	//	break;
	//case 'd': //right
	//case 'D':
	//	processPlayerMove(player, playerX + 1, playerY);
	//	break;
	//case 'e': //dig hole
	//case 'E':
	//	//if you dont have a spade you cant dig
	//	if (hasSpade == false)
	//	{
	//		printf("\nYou dont have a spade!!");
	//		_getch();
	//		break;
	//	}
	//	else
	//	{
	//		digHole(player, playerX, playerY);
	//	}
	//	break;
	//case 'q': //quits the game
	//case 'Q':
	//	exit(1);
	//	break;
	//default:
	//	printf("Invalid Input!!\n");
	//	printf("Press any key to continue:");
	//	_getch();
	//	break;
	//}

}

//----------------------------------------------------------------------------------------------
//updates the enemies getting a random move from enemy.getMove()
void Level::updateEnemies(Player & player)
{
	//char enemyMove;
	//int playerX;
	//int playerY;
	//int enemyX;
	//int enemyY;

	//player.getPosition(playerX, playerY);

	////Loop through the enemy vector
	//for (int i = 0; i < m_enemy.size(); i++)
	//{
	//	//get enemy AI movemnet 
	//	enemyMove = m_enemy[i].getMove(playerX, playerY);
	//	//get enemies current position
	//	//m_enemy[i].getPosition(enemyX, enemyY);
	//	//process the AI move
	//	switch (enemyMove)
	//	{
	//	case 'w':
	//		processEnemyMove(player, i, enemyX, enemyY - 1);
	//		break;
	//	case 's':
	//		processEnemyMove(player, i, enemyX - 1, enemyY);
	//		break;
	//	case 'a':
	//		processEnemyMove(player, i, enemyX, enemyY + 1);
	//		break;
	//	case 'd':
	//		processEnemyMove(player, i, enemyX + 1, enemyY);
	//		break;
	//	}
	//}

}

//---------------------------------------------------------------------------
char Level::getTile(int x, int y)  //Gets a tile from the board
{
	return m_levelData[y][x];
}

//---------------------------------------------------------------------------
void Level::setTile(int x, int y, char tile) //sets a tile on the board
{
	m_levelData[y][x] = tile;
}

//---------------------------------------------------------------------------
//Process the players movement
void Level::processPlayerMove(Player & player, int targetX, int targetY)
{
	//int playerX;
	//int playerY;
	//player.getPosition(playerX, playerY);

	////Get the tile that the player wants to move onto
	//char moveTile = getTile(targetX, targetY);

	////Process the tile
	//switch (moveTile)
	//{
	//case '.': //if the tile is a '.' then player can move
	//	player.setPosition(targetX, targetY);
	//	setTile(playerX, playerY, '.');
	//	setTile(targetX, targetY, '@');
	//	break;
	//case '#': //if tile is a wall player cant move so just break
	//	break;
	//case 'O': //if tile is a hole player dies and gets reset to starting point and life is lost
	//	player.setPosition(1, 1);
	//	setTile(playerX, playerY, '.');
	//	setTile(1, 1, '@');
	//	player.removeLives();
	//	printf("\nYou Fell down a hole!\n Press any key to continue:");
	//	_getch();
	//	break;
	//case 'M': //if tile is a mummy player dies and gets reset to starting point and life is lost
	//	player.setPosition(1, 1);
	//	setTile(playerX, playerY, '.');
	//	setTile(1, 1, '@');
	//	player.removeLives();
	//	break;
	//case 'S': //if tile is a spade then player can move there and gains a spade
	//	player.setPosition(targetX, targetY);
	//	setTile(playerX, playerY, '.');
	//	setTile(targetX, targetY, '@');
	//	player.addSpade();
	//	break;
	//case 'E': //if tile is a spade then player can move there and gains an energy bar
	//	player.setPosition(targetX, targetY);
	//	setTile(playerX, playerY, '.');
	//	setTile(targetX, targetY, '@');
	//	player.addEnergyBar();
	//	break;
	//case 'B':
	//	//if all energy bars are collected player can break the boulder
	//	if (player._energyBars == 8)
	//	{
	//		player.setPosition(targetX, targetY);
	//		setTile(playerX, playerY, '.');
	//		setTile(targetX, targetY, '@');
	//	}
	//	else
	//	{
	//		printf("\nYou dont have enough energy bars to pass!");
	//		_getch();
	//	}

	//	break;
	//case 'X':
	//	//game won
	//	system("CLS");
	//	printf("              -------LEVEL COMPLETE!-------\n");
	//	printf("      Congradulations you completed the level!!\n\n");
	//	printf("                Press any key to quit:");
	//	_getch();
	//	exit(1);
	//	break;
	//}
}

//-----------------------------------------------------------------------------------------------------
//processes the enemy AI move
void Level::processEnemyMove(Player & player, int enemyIndex, int targetX, int targetY)
{
	//int enemyX;
	//int enemyY;

	////gets the position of the current enemy
	//m_enemy[enemyIndex].getPosition(enemyX, enemyY);

	////stores the tile the enemy is trying to move to in char move tile
	//char moveTile = getTile(targetX, targetY);

	//switch (moveTile)
	//{
	//case '.': //enemy can move
	//	m_enemy[enemyIndex].setPosition(targetX, targetY);
	//	setTile(enemyX, enemyY, '.');
	//	setTile(targetX, targetY, m_enemy[enemyIndex].getTile());
	//	break;
	//case 'O': //enemy dies if it falls down hole
	//	m_enemy[enemyIndex].setPosition(targetX, targetY);
	//	setTile(enemyX, enemyY, '.');
	//	//remove enemy from vector if fallen down hole
	//	m_enemy[enemyIndex] = m_enemy.back();
	//	m_enemy.pop_back();
	//	enemyIndex--;
	//	break;
	//default:
	//	//any other tiles the enemy cant move
	//	break;

	//}


}

//---------------------------------------------------------------------------
//processes the players choice to dig a hole
void Level::digHole(Player &player, int targetX, int targetY)
{
	char direction;
	char tile;
	printf("Choose a direction to dig (W/S/A/D): ");
	direction = _getch();


	//sets the tile to 'O' in the direction the player chooses
	// if the tile is a '#', 'M' or 'B' the player cannot dig there
	switch (direction)
	{
	case 'w': //up
	case 'W':
		tile = getTile(targetX, targetY - 1);
		switch (tile)
		{
			//makes sure you cant dig over a wall or where a mummy is standing
		case '#':
		case 'M':
			printf("\nYou Cant dig here!");
			break;
		default:
			setTile(targetX, targetY - 1, 'O');
			player.removeSpade();
			break;
		}

		break;
	case 's': //down
	case 'S':
		tile = getTile(targetX, targetY + 1);
		switch (tile)
		{
		case '#':
		case 'M':
			printf("\nYou Cant dig here!");
			break;
		default:
			setTile(targetX, targetY + 1, 'O');
			player.removeSpade();
			break;
		}

		break;
	case 'a': //left
	case 'A':
		tile = getTile(targetX - 1, targetY);
		switch (tile)
		{
		case '#':
		case 'M':
			printf("\nYou Cant dig here!");
			break;
		default:
			setTile(targetX - 1, targetY, 'O');
			player.removeSpade();
			break;
		}

		break;
	case 'd': //right
	case 'D':
		tile = getTile(targetX + 1, targetY);
		switch (tile)
		{
		case '#':
		case 'M':
		case 'B':
			printf("\nYou Cant dig here!");
			break;
		default:
			setTile(targetX + 1, targetY, 'O');
			player.removeSpade();
			break;
		}

		break;
	default:
		printf("Invalid Input!!\n");
		printf("Press any key to continue:");
		break;
	}
}
