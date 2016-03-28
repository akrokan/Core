#ifndef CVELOCITY_H
#define CVELOCITY_H

#include "CORE/component.h"

class CVelocity : public Component
{
    float x {0}, y {0};

public:
    // Constructor
    CVelocity();

    // Functions
    float getVelX() const;
    float getVelY() const;

    void setVelX(float x);
    void setVelY(float y);
};

#endif // CVELOCITY_H
