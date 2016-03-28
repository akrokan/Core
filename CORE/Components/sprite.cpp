#include "sprite.h"

CSprite::CSprite() {}

sf::Sprite CSprite::getSprite()
{
    return sprite;
}

void CSprite::setSprite(sf::Sprite sprite)
{
    this->sprite = sprite;
}
