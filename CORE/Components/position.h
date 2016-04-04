#ifndef CPOSITION_H
#define CPOSITION_H

#include "CORE/component.h"

class CPosition : public Component
{
    int x {0}, y {0};

public:
    // Constructors
    CPosition();
    CPosition(int x, int y);

    // Functions
    int getX() const;
    int getY() const;

    void setX(int x);
    void setY(int y);
};

#endif // CPOSITION_H
