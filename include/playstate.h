#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "appengine.h"
#include "sprite.h"

class AppEngine;

class PlayState
{
    bool play {1};
    Entity E;
    Sprite Block;
    std::vector<std::shared_ptr<Entity>> shapes;

public:
    // Constructor
    PlayState(sf::RenderWindow *window, AppEngine *App);

    // Destructor
    ~PlayState() {};

    // Functions
    void Event      (sf::RenderWindow *window, AppEngine *App);
    void Update ();

    Entity getBlock();
};

#endif // PLAYSTATE_H
