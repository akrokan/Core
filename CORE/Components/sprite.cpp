#include "sprite.h"

CSprite::CSprite()
{

}

int CSprite::getSize()
{
    return spriteSize;
}

sf::Sprite CSprite::getSprite()
{
    return sprite;
}

void CSprite::setSize(int spriteSize)
{
    this->spriteSize = spriteSize;
}

void CSprite::setSprite(sf::Sprite sprite)
{
    this->sprite = sprite;
}
