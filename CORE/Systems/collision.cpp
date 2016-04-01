#include "collision.h"

Collision::Collision() { }

bool Collision::Check(std::vector<std::shared_ptr<Entity> > shapes, std::string move)
{
    auto current = shapes.front();

    if (move == "down" && (
            current->get<CPosition>()->getY() + current->get<CVelocity>()->getVelY() > 448 || (
            current->get<CPosition>()->getX() == shapes[1]->get<CPosition>()->getX() &&
            current->get<CPosition>()->getY() + current->get<CSprite>()->getSize() == shapes[1]->get<CPosition>()->getY())))
    {
        return 0;
    }

    if (move == "left" && (
            current->get<CPosition>()->getX() - current->get<CVelocity>()->getVelX() < 0 || (
            current->get<CPosition>()->getX() == shapes[1]->get<CPosition>()->getX() + shapes[1]->get<CSprite>()->getSize() &&
            current->get<CPosition>()->getY() == shapes[1]->get<CPosition>()->getY())))
    {
        return 0;
    }

    if (move == "right" && (
            current->get<CPosition>()->getX() + current->get<CVelocity>()->getVelX() > 448 || (
            current->get<CPosition>()->getX() + current->get<CSprite>()->getSize() == shapes[1]->get<CPosition>()->getX() &&
            current->get<CPosition>()->getY() == shapes[1]->get<CPosition>()->getY())))
    {
        return 0;
    }

    if (move == "up" && (
            current->get<CPosition>()->getY() - current->get<CVelocity>()->getVelY() < 0 || (
            current->get<CPosition>()->getX() == shapes[1]->get<CPosition>()->getX() &&
            current->get<CPosition>()->getY() == shapes[1]->get<CPosition>()->getY() + shapes[1]->get<CSprite>()->getSize())))
    {
        return 0;
    }

    return 1;
}
