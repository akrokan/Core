#include "include/playstate.h"

PlayState::PlayState(sf::RenderWindow *window, AppEngine *App)
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

void PlayState::Event(sf::RenderWindow *window, AppEngine *App)
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
            if (event.key.code == sf::Keyboard::Left)
            {
                shapes[0]->get<CPosition>()->setX(shapes[0]->get<CPosition>()->getX() - 40);
            }
            else if (event.key.code == sf::Keyboard::Right)
            {
                shapes[0]->get<CPosition>()->setX(shapes[0]->get<CPosition>()->getX() + 40);
            }
            else if (event.key.code == sf::Keyboard::Up)
            {
                shapes[0]->get<CPosition>()->setY(shapes[0]->get<CPosition>()->getY() - 40);
            }
            else if (event.key.code == sf::Keyboard::Down)
            {
                shapes[0]->get<CPosition>()->setY(shapes[0]->get<CPosition>()->getY() + 40);
            }
        }
    }
}

Entity PlayState::getBlock()
{
    auto pos = new CPosition;
    pos->setX(0);
    pos->setY(0);
    E.addComponent(std::type_index(typeid(CPosition)), pos);
    auto spr = new CSprite;
    spr->setSprite(Block.getSprite(0, 0));
    E.addComponent(std::type_index(typeid(CSprite)), spr);

    return E;
}

void PlayState::Update()
{
    for (std::vector<std::shared_ptr<Entity>>::iterator iter = shapes.begin() ; iter != shapes.end(); ++iter)
    {
        // Collision detection
        if ((*iter)->get<CPosition>()->getX() <= 0)
        {
            (*iter)->get<CPosition>()->setX(0);
        }
        if ((*iter)->get<CPosition>()->getX() >= 448)
        {
            (*iter)->get<CPosition>()->setX(448);
        }
        if ((*iter)->get<CPosition>()->getY() <= 0)
        {
            (*iter)->get<CPosition>()->setY(0);
        }
        if ((*iter)->get<CPosition>()->getY() >= 448)
        {
            (*iter)->get<CPosition>()->setY(448);
        }
    }
}
