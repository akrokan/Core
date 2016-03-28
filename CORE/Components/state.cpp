#include "state.h"

CState::CState()
{
    this->s = 0;
}

int CState::getS() const
{
    return s;
}

void CState::setS(int s)
{
    this->s = s;
}
