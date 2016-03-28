#include "play.h"

Play::Play(sf::RenderWindow *window, AppEngine *App)
{
    App->ChangeState("PlayState");

    // Get a block
    this->getBlock();

    // Push it on the "stack"
    shapes.push_back(std::make_shared<Entity>(E));

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
    auto size = shapes.size();
    for (unsigned int i = 0; i < size; ++i)
    {
        if (shapes[i]->get<CPosition>()->getX() <= 0)
        {
            shapes[i]->get<CPosition>()->setX(0);
        }
        if (shapes[i]->get<CPosition>()->getX() >= 448)
        {
            shapes[i]->get<CPosition>()->setX(448);
        }
        if (shapes[i]->get<CPosition>()->getY() <= 0)
        {
            shapes[i]->get<CPosition>()->setY(0);
        }
        if (shapes[i]->get<CPosition>()->getY() >= 448)
        {
            shapes[i]->get<CPosition>()->setY(448);
        }

        if (shapes[i]->get<CPosition>()->getY() >= 300 && shapes[i]->get<CState>()->getS() == 0)
        {
            shapes[i]->get<CState>()->setS(1);
            auto block = this->getBlock();
            shapes.push_back(std::make_shared<Entity>(block));
        }
    }
    for (std::vector<std::shared_ptr<Entity>>::iterator iter = shapes.begin() ; iter != shapes.end(); ++iter)
    {
        // Collision detection
//        if ((*iter)->get<CPosition>()->getX() <= 0)
//        {
//            (*iter)->get<CPosition>()->setX(0);
//        }
//        if ((*iter)->get<CPosition>()->getX() >= 448)
//        {
//            (*iter)->get<CPosition>()->setX(448);
//        }
//        if ((*iter)->get<CPosition>()->getY() <= 0)
//        {
//            (*iter)->get<CPosition>()->setY(0);
//        }
//        if ((*iter)->get<CPosition>()->getY() >= 448)
//        {
//            (*iter)->get<CPosition>()->setY(448);
//        }

//        if ((*iter)->get<CState>()->getS() == 0)
//        {
//        if (((*iter)->get<CPosition>()->getY() >= 300))// && ((*iter)->get<CState>()->getS() == 0))
//        {
//            (*iter)->get<CState>()->setS(1);
//            std::cout << (*iter)->get<CState>()->getS() << std::endl;
//            auto block = this->getBlock();
//            shapes.pop_back();
//            shapes.push_back(std::make_shared<Entity>(block));
//        }
//        }
    }
}
