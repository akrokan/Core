#ifndef CSHAPE_H
#define CSHAPE_H

#include "SFML/Graphics/ConvexShape.hpp"

#include "CORE/component.h"

class CShape : public Component
{
    sf::ConvexShape shape;

public:
    // Constructor
    CShape();

    // Functions
    sf::ConvexShape getShape();

    void setShape(sf::ConvexShape shape);
};

#endif // CSHAPE_H
