#ifndef COLLISION_H
#define COLLISION_H

#include <memory>

#include "CORE/Components/position.h"
#include "CORE/Components/velocity.h"
#include "CORE/entity.h"

class Collision
{
public:
    Collision();

    // Functions
    static bool Check(std::shared_ptr<Entity> shape, std::string move);
};

#endif // COLLISION_H
