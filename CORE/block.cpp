#include "block.h"

Block::Block() {}

Entity Block::getBlock()
{
//    Block B;
//    Entity E;
//    sf::Sprite sprite;
//    sf::Texture texture;

    // set position
    auto pos = new CPosition;
    pos->setX(32);
    pos->setY(32);
    E.addComponent(std::type_index(typeid(CPosition)), pos);

    // set sprite from a spritesheet
    auto spr = new CSprite;
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

sf::Sprite Block::getSprite(int x, int y)
{
    if (!texture.loadFromFile("image.png", sf::IntRect(x, y, spriteSize, spriteSize)))
    {
        std::cout << "Error: sprite sheet not found" << std::endl;
    }

    sprite.setTexture(texture);

    return sprite;
}
