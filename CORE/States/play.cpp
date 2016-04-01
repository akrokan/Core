#include "play.h"

Play::Play(sf::RenderWindow *window, AppEngine *App)
{
    App->ChangeState("PlayState");

    // Get a block
    auto block = B.getBlock();
    shapes.push_back(std::make_shared<Entity>(block));

    // Place a wall
    auto wall = Block::getWall();
    shapes.push_back(std::make_shared<Entity>(wall));

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
            // only the first shape can take actions
            auto shape = shapes.front();

            // actions possible with a shape
            if (event.key.code == sf::Keyboard::Left)
            {
                if (Collision::Check(shapes, "left"))
                    Movement::left(shape);
            }
            else if (event.key.code == sf::Keyboard::Right)
            {
                if (Collision::Check(shapes, "right"))
                    Movement::right(shape);
            }
            else if (event.key.code == sf::Keyboard::Up)
            {
                if (Collision::Check(shapes, "up"))
                    Movement::up(shape);
            }
            else if (event.key.code == sf::Keyboard::Down)
            {
                if (Collision::Check(shapes, "down"))
                    Movement::down(shape);
            }
            else if (event.key.code == sf::Keyboard::Space)
            {
                auto block = B.getBlock();
                shapes.push_back(std::make_shared<Entity>(block));
            }
        }
    }
}

void Play::Update()
{
//        if (std::abs(current->get<CPosition>()->getX() - shapes[1]->get<CPosition>()->getX()) <=
//                std::numeric_limits<float>::epsilon() *
//                std::max(std::abs(current->get<CPosition>()->getX()), std::abs(shapes[1]->get<CPosition>()->getX())) *
//                1)
}
