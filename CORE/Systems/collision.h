#ifndef COLLISION_H
#define COLLISION_H

#include  "CORE/appengine.h"

class Collision
{
public:
    Collision();

    // Functions
    static bool Check(std::shared_ptr<Entity> shape, std::string move);
};

#endif // COLLISION_H
