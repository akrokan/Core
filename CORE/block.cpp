#include "block.h"

Block::Block() {}

sf::Sprite Block::getSprite(int x, int y)
{
    if (!texture.loadFromFile("image.png", sf::IntRect(x, y, spriteSize, spriteSize)))
    {
        std::cout << "Error: sprite sheet not found" << std::endl;
    }

    sprite.setTexture(texture);

    return sprite;
}
