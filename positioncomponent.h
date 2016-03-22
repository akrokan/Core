#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include "component.h"

class PositionComponent : public Component
{
    float x {0}, y {0};

public:
    // Constructors
    PositionComponent();
    PositionComponent(float x, float y);

    // Functions
    float getX() const;
    float getY() const;

    void setX(float x);
    void setY(float y);
};

#endif // POSITIONCOMPONENT_H
