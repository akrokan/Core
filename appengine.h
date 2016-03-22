#ifndef APPENGINE_H
#define APPENGINE_H

#include <iostream>
#include <stack>
#include <string>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "entity.h"
#include "menustate.h"
#include "playstate.h"
#include "positioncomponent.h"
//#include "sprite.h"
#include "spritecomponent.h"

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
    void Event(std::vector<std::shared_ptr<Entity>> shapes, AppEngine *App);
//    void Event(AppEngine *App, Entity *Shape);
    void Init();
    void Update(std::vector<std::shared_ptr<Entity>> shapes);

    void ChangeState(std::string state);
    void PopState();

    bool Running();
    void Quit();
};

#endif // APPENGINE_H
