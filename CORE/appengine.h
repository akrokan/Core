#ifndef APPENGINE_H
#define APPENGINE_H

#include <iostream>
#include <memory>
#include <stack>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "entity.h"
#include "Components/position.h"
#include "Components/sprite.h"
#include "States/play.h"

class AppEngine
{
    // Variables
    bool isRunning {0};
    sf::RenderWindow window;
    std::stack<std::string> states;

public:
    // Constructor
    AppEngine() {};

    // Functions
    void Draw(std::vector<std::shared_ptr<Entity>> shapes);
    void Event(AppEngine *App);
    void Init();
    void Update(std::vector<std::shared_ptr<Entity>> shapes);

    void ChangeState(std::string state);
    void PopState();

    bool Running();
    void Quit();
};

#endif // APPENGINE_H
