#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <memory>

#include "CORE/Components/position.h"
#include "CORE/Components/velocity.h"
#include "CORE/entity.h"

class Movement
{
    Entity* shape;

public:
    // Constructor
    Movement();

    // Functions
    static void down    (std::shared_ptr<Entity> shape);
    static void left    (std::shared_ptr<Entity> shape);
    static void right   (std::shared_ptr<Entity> shape);
    static void up      (std::shared_ptr<Entity> shape);
};

#endif // MOVEMENT_H
