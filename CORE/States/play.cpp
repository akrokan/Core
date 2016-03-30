#include "play.h"

Play::Play(sf::RenderWindow *window, AppEngine *App)
{
    App->ChangeState("PlayState");

    // Get a block
    auto block = B.getBlock();

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
                auto block = B.getBlock();
                shapes.push_back(std::make_shared<Entity>(block));
            }
        }
    }
}

void Play::Update()
{

}
