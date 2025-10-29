#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Board.h"


int main()
{
    srand(time(NULL));

    bool firstClick = true;

    Board board;
    board.setSize(20, 20);
    board.newBoard();
    int mines = 50;
    board.fillBoard(mines);

    int height = board.vector[0][0].textureSize.x * board.size.y;
    int width = board.vector[0][0].textureSize.y * board.size.x;
    sf::RenderWindow window(sf::VideoMode(width, height), "Minesweeper");

    window.setKeyRepeatEnabled(false);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed)
        {
            sf::Vector2i mousePos = board.getPosOfTile(event.mouseButton.x, event.mouseButton.y);
            if (firstClick)
            {
                firstClick = false;
                while (board.vector[mousePos.y][mousePos.x].value != 0)
                {
                    board.newBoard();
                    board.fillBoard(mines);
                    //std::cout << "generating" << std::endl;
                }
            }
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                //std::cout << "tile x: " << mousePos.x << " " << "tile y: " << mousePos.y << std::endl;
                board.updateBoard(mousePos);
            }
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                //std::cout << "tile x: " << mousePos.x << " " << "tile y: " << mousePos.y << std::endl;
                board.updateBoardFlag(mousePos);
            }
        }

        window.clear();
        for (int i = 0; i < board.size.x; i++)
        {
            for (int j = 0; j < board.size.y; j++)
            {
                window.draw(board.vector[j][i].sprite);
            }
        }
        window.display();
    }

    return 0;
}