#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Tile
{
    
public:
    sf::Sprite sprite;
    int value;
    bool is_hidden;
    bool is_marked;
    sf::Texture texture;
    sf::Vector2u textureSize;
    sf::Vector2<int> position;

    void setTextureFromAtlas();
};
