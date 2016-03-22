#include "positioncomponent.h"

PositionComponent::PositionComponent() { }

float PositionComponent::getX() const
{
    return x;
}

float PositionComponent::getY() const
{
    return y;
}

void PositionComponent::setX(float x)
{
    this->x = x;
}

void PositionComponent::setY(float y)
{
    this->y = y;
}
