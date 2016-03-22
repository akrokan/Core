#include "playstate.h"

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
                shapes[0]->get<PositionComponent>()->setX(shapes[0]->get<PositionComponent>()->getX() - 40);
            }
            else if (event.key.code == sf::Keyboard::Right)
            {
                shapes[0]->get<PositionComponent>()->setX(shapes[0]->get<PositionComponent>()->getX() + 40);
            }
            else if (event.key.code == sf::Keyboard::Up)
            {
                shapes[0]->get<PositionComponent>()->setY(shapes[0]->get<PositionComponent>()->getY() - 40);
            }
            else if (event.key.code == sf::Keyboard::Down)
            {
                shapes[0]->get<PositionComponent>()->setY(shapes[0]->get<PositionComponent>()->getY() + 40);
            }
        }
    }
}

Entity PlayState::getBlock()
{
    auto pos = new PositionComponent;
    pos->setX(0);
    pos->setY(0);
    E.addComponent(std::type_index(typeid(PositionComponent)), pos);
    SpriteComponent* spr = new SpriteComponent;
    spr->setSprite(Block.getSprite(0, 0));
    E.addComponent(std::type_index(typeid(SpriteComponent)), spr);

    return E;
}

void PlayState::Update()
{
    for (std::vector<std::shared_ptr<Entity>>::iterator iter = shapes.begin() ; iter != shapes.end(); ++iter)
    {
        // Collision detection
        if ((*iter)->get<PositionComponent>()->getX() <= 0)
        {
            (*iter)->get<PositionComponent>()->setX(0);
        }
        if ((*iter)->get<PositionComponent>()->getX() >= 448)
        {
            (*iter)->get<PositionComponent>()->setX(448);
        }
        if ((*iter)->get<PositionComponent>()->getY() <= 0)
        {
            (*iter)->get<PositionComponent>()->setY(0);
        }
        if ((*iter)->get<PositionComponent>()->getY() >= 448)
        {
            (*iter)->get<PositionComponent>()->setY(448);
        }
    }
}
