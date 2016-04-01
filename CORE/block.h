#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "CORE/Components/position.h"
#include "CORE/Components/sprite.h"
#include "CORE/Components/state.h"
#include "CORE/Components/velocity.h"
#include "CORE/entity.h"

class Block
{
    Entity E;
    int x {0}, y {0};
    sf::Sprite sprite;
    sf::Texture texture;

public:
    // Constructor
    Block();

    // Functions
    Entity getBlock();
    static Entity getWall();
    sf::Sprite getSprite(int x, int y);
};

#endif // BLOCK_H
