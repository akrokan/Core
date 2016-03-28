#include "velocity.h"

CVelocity::CVelocity()
{

}

float CVelocity::getVelX() const
{
    return x;
}

float CVelocity::getVelY() const
{
    return y;
}

void CVelocity::setVelX(float x)
{
    this->x = x;
}

void CVelocity::setVelY(float y)
{
    this->y = y;
}
