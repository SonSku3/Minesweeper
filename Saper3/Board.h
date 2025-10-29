#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class Board
{
public:
	std::vector<std::vector<Tile>> vector;
	sf::Vector2<int> size;

	void setSize(int n, int m);
	void newBoard();
	void fillBoard(int mines_num);
	sf::Vector2i getPosOfTile(int x, int y);
	void updateTextures();
	bool neighbouring(int y, int x, int value);
	void floodFill(int y, int x);
	void updateBoard(sf::Vector2i pos);
	void updateBoardFlag(sf::Vector2i pos);
	bool checkForWin();
	void endOfGame();
};

