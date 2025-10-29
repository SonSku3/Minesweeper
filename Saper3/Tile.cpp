#include "Tile.h"

void Tile::setTextureFromAtlas()
{
    texture.loadFromFile("Minesweeper_texture.png");
    sprite.setTexture(texture);
    textureSize = texture.getSize();
    textureSize.x /= 4;
    textureSize.y /= 4;
    
    if (is_marked == true)
    {
        sprite.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 2, textureSize.x, textureSize.y));//flag
    }
    else if (is_hidden == true)
    {
        sprite.setTextureRect(sf::IntRect(textureSize.x, textureSize.y * 2, textureSize.x, textureSize.y));//hidden
    }
    else
    {
        switch (value)
        {
        case 0:
            sprite.setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));//empty
            break;
        case 1:
            sprite.setTextureRect(sf::IntRect(textureSize.x, 0, textureSize.x, textureSize.y));//1
            break;
        case 2:
            sprite.setTextureRect(sf::IntRect(textureSize.x * 2, 0, textureSize.x, textureSize.y));//2
            break;
        case 3:
            sprite.setTextureRect(sf::IntRect(textureSize.x * 3, 0, textureSize.x, textureSize.y));//3
            break;
        case 4:
            sprite.setTextureRect(sf::IntRect(0, textureSize.y, textureSize.x, textureSize.y));//4
            break;
        case 5:
            sprite.setTextureRect(sf::IntRect(textureSize.x, textureSize.y, textureSize.x, textureSize.y));//5
            break;
        case 6:
            sprite.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y, textureSize.x, textureSize.y));//6
            break;
        case 7:
            sprite.setTextureRect(sf::IntRect(textureSize.x * 3, textureSize.y, textureSize.x, textureSize.y));//7
            break;
        case 8:
            sprite.setTextureRect(sf::IntRect(0, textureSize.y * 2, textureSize.x, textureSize.y));//8
            break;
        case -1:
            sprite.setTextureRect(sf::IntRect(0, textureSize.y * 3, textureSize.x, textureSize.y));//mine
            break;
        case -2:
            sprite.setTextureRect(sf::IntRect(textureSize.x, textureSize.y * 3, textureSize.x, textureSize.y));//activated mine
            break;
        default:
            std::cout << "setTextureFromAtlas ERROR" << std::endl;
            break;
        }
    }
    //tile.setTextureRect(sf::IntRect(textureSize.x * 3, textureSize.y * 2, textureSize.x, textureSize.y));//red flag
}
