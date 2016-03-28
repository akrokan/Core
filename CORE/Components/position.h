#ifndef CPOSITION_H
#define CPOSITION_H

#include "CORE/component.h"

class CPosition : public Component
{
    float x {0}, y {0};

public:
    // Constructors
    CPosition();
    CPosition(float x, float y);

    // Functions
    float getX() const;
    float getY() const;

    void setX(float x);
    void setY(float y);
};

#endif // CPOSITION_H
