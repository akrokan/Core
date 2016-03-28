#ifndef STATE_H
#define STATE_H

#include "CORE/component.h"

class CState : public Component
{
    int s {0};

public:
    // Constructor
    CState();

    // Functions
    int getS() const;

    void setS(int s);
};

#endif // STATE_H
