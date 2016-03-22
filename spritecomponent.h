#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "SFML/Graphics.hpp"

#include "component.h"

class SpriteComponent : public Component
{
    sf::Sprite sprite;
    sf::Texture texture;

public:
    // Constructor
    SpriteComponent();

    // Functions
    sf::Sprite getSprite();

    void setSprite(sf::Sprite sprite);
};

#endif // SPRITECOMPONENT_H
