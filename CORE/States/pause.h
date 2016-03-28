#ifndef PAUSE_H
#define PAUSE_H

#include "CORE/appengine.h"

class AppEngine;

class Pause
{
    // Variables
    bool pause {1};

public:
    // Constructor
    Pause(AppEngine *App, sf::RenderWindow *window);

    // Destructor
    ~Pause() {};

    // Functions
    void Draw       (sf::RenderWindow *window);
    void Event      (AppEngine *App, sf::RenderWindow *window);
    void Instance   (AppEngine *App, sf::RenderWindow *window);
};

#endif // PAUSE_H
