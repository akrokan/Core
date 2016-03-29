#include "play.h"

Play::Play(sf::RenderWindow *window, AppEngine *App)
{
    App->ChangeState("PlayState");

    // Get a block
//    auto block = this->getBlock();
    auto block = Block::getBlock();

    // Push it on the "stack"
    shapes.push_back(std::make_shared<Entity>(block));

    while (play)
    {
        App->Draw(shapes);
        this->Event(window, App);
        this->Update();
    }
}

void Play::Event(sf::RenderWindow *window, AppEngine *App)
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            App->PopState();
            play = 0;
            App->Quit();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            // only the first shape is can take actions
            auto shape = shapes.back();

            // actions possible with a shape
            if (event.key.code == sf::Keyboard::Left)
            {
                Movement::left(shape);
            }
            else if (event.key.code == sf::Keyboard::Right)
            {
                Movement::right(shape);
            }
            else if (event.key.code == sf::Keyboard::Up)
            {
                Movement::up(shape);
            }
            else if (event.key.code == sf::Keyboard::Down)
            {
                Movement::down(shape);
            }
            else if (event.key.code == sf::Keyboard::Space)
            {
                Movement::drop(shape);
                auto block = this->getBlock();
                shapes.push_back(std::make_shared<Entity>(block));
            }
        }
    }
}

Entity Play::getBlock()
{
//    Block B;
    // set position
    auto pos = new CPosition;
    pos->setX(0);
    pos->setY(0);
    E.addComponent(std::type_index(typeid(CPosition)), pos);

    // set sprite from a spritesheet
    auto spr = new CSprite;
    spr->setSprite(B.getSprite(0, 0)); // coordinates in spritesheet
    E.addComponent(std::type_index(typeid(CSprite)), spr);

    // set state (0 = moveable)
    auto sta = new CState;
    sta->setS(0);
    E.addComponent(std::type_index(typeid(CState)), sta);

    // set velocity
    auto vel = new CVelocity;
    vel->setVelX(32);
    vel->setVelY(32);
    E.addComponent(std::type_index(typeid(CVelocity)), vel);

    return E;
}

void Play::Update()
{

}
