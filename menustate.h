#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "appengine.h"

class AppEngine;

class MenuState
{
    // Variables
    bool pause {1};

public:
    // Constructor
    MenuState(AppEngine *App, sf::RenderWindow *window);

    // Destructor
    ~MenuState() {};

    // Functions
    void Draw       (sf::RenderWindow *window);
    void Event      (AppEngine *App, sf::RenderWindow *window);
    void Instance   (AppEngine *App, sf::RenderWindow *window);
};

#endif // MENUSTATE_H
