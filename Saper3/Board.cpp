#include "Board.h"
#include <math.h>

void Board::setSize(int n, int m)
{
	size.x = n;
	size.y = m;
}

void Board::newBoard()
{
	vector.clear();
	Tile x;
	x.value = 0;
	x.is_hidden = true;
	std::vector<Tile> temp;
	for (int i = 0; i < size.x; i++)
	{
		temp.push_back(x);
	}
	for (int i = 0; i < size.y; i++)
	{
		vector.push_back(temp);
	}
}

void Board::fillBoard(int mines_num)
{
	for (int i = 0; i < mines_num; i++)
	{
		int x = rand() % size.y;
		int y = rand() % size.x;
		vector[x][y].value = -1;
	}
	std::vector<std::vector<int>> p = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
	for (int i = 0; i < size.y; i++)
	{
		for (int j = 0; j < size.x; j++)
		{
			if (vector[i][j].value != -1)
			{
				int sum = 0;
				for (int k = 0; k < p.size(); k++)
				{
					int i_n = i + p[k][0];
					int j_n = j + p[k][1];
					
					if (i_n >= 0 && i_n < size.y && j_n >= 0 && j_n < size.x)
					{
						if (vector[i_n][j_n].value == -1)
						{
							sum++;
						}
					}
				}
				vector[i][j].value = sum;
			}
			vector[i][j].setTextureFromAtlas();
			sf::Vector2u textureSize = vector[i][j].texture.getSize();
			textureSize.x /= 4;
			textureSize.y /= 4;
			vector[i][j].sprite.setPosition(j * textureSize.x, i * textureSize.y);
		}
	}
}

sf::Vector2i Board::getPosOfTile(int x, int y)
{
	int i = int(x / vector[0][0].textureSize.x);
	int j = int(y / vector[0][0].textureSize.y);
	sf::Vector2i pos = { i, j };
	return pos;
}

void Board::updateTextures()
{
	for (int i = 0; i < size.y; i++)
	{
		for (int j = 0; j < size.x; j++)
		{
			vector[i][j].setTextureFromAtlas();
		}
	}
}

bool Board::neighbouring(int y, int x, int value)
{
	std::vector<std::vector<int>> p = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
	for (int k = 0; k < p.size(); k++)
	{
		if (y + p[k][0] >= 0 && y + p[k][0] < size.y && x + p[k][1] >= 0 && x + p[k][1] < size.x)
		{
			if (vector[y + p[k][0]][x + p[k][1]].value == value)
			{
				return true;
			}
		}
	}
	return false;
}

void Board::floodFill(int y, int x)
{
	if (x < 0 || x >= size.x || y < 0 || y >= size.y)
	{
		return;
	}
	if (neighbouring(y, x, 0) == false)
	{
		return;
	}
	if (vector[y][x].is_hidden == false)
	{
		return;
	}
	vector[y][x].is_hidden = false;

	floodFill(y + 1, x);
	floodFill(y - 1, x);
	floodFill(y, x + 1);
	floodFill(y, x - 1);
}

bool Board::checkForWin()
{
	for (int i = 0; i < size.y; i++)
	{
		for (int j = 0; j < size.x; j++)
		{
			if (vector[i][j].is_hidden && vector[i][j].value != -1)
			{
				return false;
			}
		}
	}
	return true;
}

void Board::endOfGame()
{
	for (int i = 0; i < size.y; i++)
	{
		for (int j = 0; j < size.x; j++)
		{
			vector[i][j].is_marked = false;
			vector[i][j].is_hidden = false;
		}
	}
}

void Board::updateBoard(sf::Vector2i pos)
{
	if (checkForWin() == true)
	{
		std::cout << "win" << std::endl;
		endOfGame();
	}

	if (vector[pos.y][pos.x].is_marked == true)
	{
		return;
	}
	else
	{
		if (vector[pos.y][pos.x].value == 0)
		{
			floodFill(pos.y, pos.x);
			vector[pos.y][pos.x].is_hidden = false;
		}
		else if (vector[pos.y][pos.x].value == -1)
		{
			std::cout << "Game over" << std::endl;
			vector[pos.y][pos.x].value = -2;
			for (int i = 0; i < size.y; i++)
			{
				for (int j = 0; j < size.x; j++)
				{
					vector[i][j].is_hidden = false;
				}
			}
		}
		else
		{
			vector[pos.y][pos.x].is_hidden = false;
		}
	}
	
	updateTextures();
}

void Board::updateBoardFlag(sf::Vector2i pos)
{
	if (vector[pos.y][pos.x].is_marked == false)
	{
		vector[pos.y][pos.x].is_marked = true;
	}
	else
	{
		vector[pos.y][pos.x].is_marked = false;
	}
	updateTextures();
}

