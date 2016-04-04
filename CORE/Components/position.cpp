#include "position.h"

CPosition::CPosition()
{

}

CPosition::CPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

int CPosition::getX() const
{
    return x;
}

int CPosition::getY() const
{
    return y;
}

void CPosition::setX(int x)
{
    this->x = x;
}

void CPosition::setY(int y)
{
    this->y = y;
}
