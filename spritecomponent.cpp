#include "spritecomponent.h"

SpriteComponent::SpriteComponent() { }

sf::Sprite SpriteComponent::getSprite()
{
    return sprite;
}

void SpriteComponent::setSprite(sf::Sprite sprite)
{
    this->sprite = sprite;
}
