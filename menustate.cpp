#include "menustate.h"

MenuState::MenuState(AppEngine *App, sf::RenderWindow *window)
{
    App->ChangeState("MenuState");

    while (pause)
    {
        this->Draw(window);
        this->Event(App, window);
    }
}

void MenuState::Draw(sf::RenderWindow *window)
{
    window->clear(sf::Color::Blue);
    window->display();
}

void MenuState::Event(AppEngine *App, sf::RenderWindow *window)
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            App->PopState();
            pause = 0;
            window->close();
            App->Quit();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::P)
            {
                App->PopState();
                pause = 0;
            }
        }
    }
}
