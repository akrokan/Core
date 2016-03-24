#ifndef CSPRITE_H
#define CSPRITE_H

#include "SFML/Graphics.hpp"

#include "include/component.h"

class CSprite : public Component
{
    sf::Sprite sprite;
    sf::Texture texture;

public:
    // Constructor
    CSprite();

    // Functions
    sf::Sprite getSprite();

    void setSprite(sf::Sprite sprite);
};

#endif // CSPRITE_H
