#include "block.h"

Block::Block() { }

Entity Block::getBlock()
{
    // set position
    auto pos = new CPosition;
    pos->setX(32);
    pos->setY(32);
    E.addComponent(std::type_index(typeid(CPosition)), pos);

    // set sprite from a spritesheet
    auto spr = new CSprite;
    spr->setSize(32);
    spr->setSprite(this->getSprite(0, 0)); // coordinates in spritesheet
    E.addComponent(std::type_index(typeid(CSprite)), spr);

    // set state (0 = moveable)
    auto sta = new CState;
    sta->setS(0);
    E.addComponent(std::type_index(typeid(CState)), sta);

    // set velocity
    auto vel = new CVelocity;
    vel->setVelX(32);
    vel->setVelY(32);
    E.addComponent(std::type_index(typeid(CVelocity)), vel);

    return E;
}

Entity Block::getWall()
{
    Block B;
    Entity E;

    // set position
    auto pos = new CPosition;
    pos->setX(96);
    pos->setY(96);
    E.addComponent(std::type_index(typeid(CPosition)), pos);

    // set sprite from a spritesheet
    auto spr = new CSprite;
    spr->setSize(32);
    spr->setSprite(B.getSprite(1, 1)); // coordinates in spritesheet
    E.addComponent(std::type_index(typeid(CSprite)), spr);

    return E;
}

sf::Sprite Block::getSprite(int x, int y)
{
    auto spriteSize = 32;
    if (!texture.loadFromFile("image.png", sf::IntRect(x * spriteSize, y * spriteSize, spriteSize, spriteSize)))
    {
        std::cout << "Error: sprite sheet not found" << std::endl;
    }

    sprite.setTexture(texture);

    return sprite;
}
