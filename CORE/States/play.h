#ifndef PLAY_H
#define PLAY_H

#include "CORE/appengine.h"
#include "CORE/block.h"
#include "CORE/Systems/movement.h"
#include "CORE/Systems/collision.h"

class AppEngine;

class Play
{
    bool play {1};
    Block B;
    std::vector<std::shared_ptr<Entity>> shapes;

public:
    // Constructor
    Play(sf::RenderWindow *window, AppEngine *App);

    // Destructor
    ~Play() {};

    // Functions
    void Event (sf::RenderWindow *window, AppEngine *App);
    void Update ();

    Entity getBlock();
};

#endif // PLAY_H
