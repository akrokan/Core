#ifndef ENTITY_H
#define ENTITY_H

#include <map>
#include <memory>
#include <string>
#include <typeindex>

#include "component.h"

class Component;

class Entity
{
    std::string type;
    std::map<std::type_index, Component*> components;

public:
    // Constructor
    Entity();

    // Destructor
    ~Entity();

    // Functions
    std::string getType() const;
    void setType(const std::string& type);

    template <typename T>
    T* get()
    {
        auto it = components.find(std::type_index(typeid(T)));
        if (it != components.end())
        {
            return dynamic_cast<T*>(it->second);
        }
        return nullptr;
    }
    void addComponent(std::type_index type, Component* c);
};

#endif // ENTITY_H
