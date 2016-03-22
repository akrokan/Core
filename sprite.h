#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Sprite
{
    int x {0}, y {0};
    sf::Sprite sprite;
    sf::Texture texture;
    unsigned int spriteSize {32};

public:
    // Constructor
    Sprite();

    // Functions
    sf::Sprite getSprite (int x, int y);
};

#endif // SPRITE_H
