#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Block
{
    int x {0}, y {0};
    sf::Sprite sprite;
    sf::Texture texture;
    unsigned int spriteSize {32};

public:
    // Constructor
    Block();

    // Functions
    sf::Sprite getSprite (int x, int y);
};

#endif // BLOCK_H
