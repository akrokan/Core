#include "boundingbox.h"

CBoundingBox::CBoundingBox()
{

}

CBoundingBox::CBoundingBox (int height, int width)
{
    this->height = height;
    this->width = width;
}

int CBoundingBox::getBoundHeight() const
{
    return height;
}

int CBoundingBox::getBoundWidth() const
{
    return width;
}

void CBoundingBox::setBoundHeight(int height)
{
    this->height = height;
}

void CBoundingBox::setBoundWidth(int width)
{
    this->width = width;
}
