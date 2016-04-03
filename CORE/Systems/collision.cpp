#include "collision.h"

Collision::Collision() { }

bool Collision::Check(std::vector<std::shared_ptr<Entity> > shapes, std::string move)
{
    auto current = shapes.front();

    for (unsigned int i {1}; i < shapes.size(); ++i)
    {
        if (move == "down" && (
                current->get<CPosition>()->getY() + current->get<CVelocity>()->getVelY() > 448 || (
                current->get<CPosition>()->getX() == shapes[i]->get<CPosition>()->getX() &&
                current->get<CPosition>()->getY() + current->get<CSprite>()->getSize() == shapes[i]->get<CPosition>()->getY())))
        {
            return 0;
        }

        if (move == "left" && (
                current->get<CPosition>()->getX() - current->get<CVelocity>()->getVelX() < 0 || (
                current->get<CPosition>()->getX() == shapes[i]->get<CPosition>()->getX() + shapes[i]->get<CSprite>()->getSize() &&
                current->get<CPosition>()->getY() == shapes[i]->get<CPosition>()->getY())))
        {
            return 0;
        }

        if (move == "right" && (
                current->get<CPosition>()->getX() + current->get<CVelocity>()->getVelX() > 448 || (
                current->get<CPosition>()->getX() + current->get<CSprite>()->getSize() == shapes[i]->get<CPosition>()->getX() &&
                current->get<CPosition>()->getY() == shapes[i]->get<CPosition>()->getY())))
        {
            return 0;
        }

        if (move == "up" && (
                current->get<CPosition>()->getY() - current->get<CVelocity>()->getVelY() < 0 || (
                current->get<CPosition>()->getX() == shapes[i]->get<CPosition>()->getX() &&
                current->get<CPosition>()->getY() == shapes[i]->get<CPosition>()->getY() + shapes[i]->get<CSprite>()->getSize())))
        {
            return 0;
        }
    }

    return 1;
}
