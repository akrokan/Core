#include "collision.h"

Collision::Collision()
{

}

bool Collision::Check(std::shared_ptr<Entity> shape, std::string move)
{
    if (move == "left" && shape->get<CPosition>()->getX() - shape->get<CVelocity>()->getVelX() < 0)
    {
        return 0;
    }
    if (move == "right" && shape->get<CPosition>()->getX() + shape->get<CVelocity>()->getVelX() > 448)
    {
        return 0;
    }
    if (move == "up" && shape->get<CPosition>()->getY() - shape->get<CVelocity>()->getVelY() < 0)
    {
        return 0;
    }
    if (move == "down" && shape->get<CPosition>()->getY() + shape->get<CVelocity>()->getVelY() > 448)
    {
        return 0;
    }

    return 1;
}
