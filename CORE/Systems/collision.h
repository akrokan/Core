#ifndef COLLISION_H
#define COLLISION_H

#include <memory>
#include <vector>

#include "CORE/Components/position.h"
#include "CORE/Components/sprite.h"
#include "CORE/Components/velocity.h"
#include "CORE/entity.h"

class Collision
{
public:
    Collision();

    // Functions
    static bool Check(std::vector<std::shared_ptr<Entity>> shapes, std::string move);
};

#endif // COLLISION_H
