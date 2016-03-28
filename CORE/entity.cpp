#include "entity.h"

Entity::Entity() {}

Entity::~Entity() {}

void Entity::addComponent(std::type_index type, Component* c)
{
    components[type] = c;
}

std::string Entity::getType() const
{
    return type;
}

void Entity::setType(const std::string& type)
{
    this->type = type;
}
