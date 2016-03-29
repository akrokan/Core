#include "movement.h"

Movement::Movement()
{

}

void Movement::down(std::shared_ptr<Entity> shape)
{
    if (Collision::Check(shape, "down") == 1)
    {
        shape->get<CPosition>()->setY(shape->get<CPosition>()->getY() + shape->get<CVelocity>()->getVelY());
    }
}

void Movement::drop(std::shared_ptr<Entity> shape)
{

}

void Movement::left(std::shared_ptr<Entity> shape)
{
    if (Collision::Check(shape, "left") == 1)
    {
        shape->get<CPosition>()->setX(shape->get<CPosition>()->getX() - shape->get<CVelocity>()->getVelX());
    }
}

void Movement::right(std::shared_ptr<Entity> shape)
{
    if (Collision::Check(shape, "right") == 1)
    {
        shape->get<CPosition>()->setX(shape->get<CPosition>()->getX() + shape->get<CVelocity>()->getVelX());
    }
}

void Movement::up(std::shared_ptr<Entity> shape)
{
    if (Collision::Check(shape, "up") == 1)
    {
        shape->get<CPosition>()->setY(shape->get<CPosition>()->getY() - shape->get<CVelocity>()->getVelY());
    }
}
