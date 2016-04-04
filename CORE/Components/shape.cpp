#include "shape.h"

CShape::CShape()
{

}

sf::ConvexShape CShape::getShape()
{
    return shape;
}

void CShape::setShape(sf::ConvexShape shape)
{
    this->shape = shape;
}
