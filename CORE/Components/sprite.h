#ifndef CSPRITE_H
#define CSPRITE_H

#include "SFML/Graphics.hpp"

#include "CORE/component.h"

class CSprite : public Component
{
    sf::Sprite sprite;
    sf::Texture texture;
    unsigned int spriteSize {32};

public:
    // Constructor
    CSprite();

    // Functions
    int getSize();
    sf::Sprite getSprite();

    void setSize(int spriteSize);
    void setSprite(sf::Sprite sprite);
};

#endif // CSPRITE_H
