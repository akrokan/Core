#include "position.h"

CPosition::CPosition() {}

float CPosition::getX() const
{
    return x;
}

float CPosition::getY() const
{
    return y;
}

void CPosition::setX(float x)
{
    this->x = x;
}

void CPosition::setY(float y)
{
    this->y = y;
}
