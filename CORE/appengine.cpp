#include "appengine.h"

const int SCREEN_WIDTH {480};
const int SCREEN_HEIGHT {480};

void AppEngine::ChangeState(std::string state)
{
    states.push(state);
    std::cout << states.top() << std::endl;
}

void AppEngine::Draw(std::vector<std::shared_ptr<Entity>> shapes)
{
    window.clear(sf::Color::Black);

    for (std::vector<std::shared_ptr<Entity>>::iterator iter = shapes.begin() ; iter != shapes.end(); ++iter)
    {
        auto shape = (*iter)->get<CSprite>()->getSprite();
        shape.setPosition(sf::Vector2f((*iter)->get<CPosition>()->getX(), (*iter)->get<CPosition>()->getY()));

        window.draw(shape);
    }

    window.display();
}

void AppEngine::Event(AppEngine *App)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
            isRunning = 0;
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::P)
            {

            }
            if (event.key.code == sf::Keyboard::Space)
            {
                Play Play(&window, App);
            }
        }
    }
}

void AppEngine::Init()
{
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "App");
    window.setFramerateLimit(60);
    isRunning = 1;

    states.push("IdleState");
    std::cout << states.top() << std::endl;

    std::cout << "Press space to start" << std::endl;
}

void AppEngine::PopState()
{
    states.pop();
    std::cout << states.top() << std::endl;
}

void AppEngine::Quit()
{
    isRunning = 0;
    std::cout << "Bye" << std::endl;
}

bool AppEngine::Running()
{
    return isRunning;
}

void AppEngine::Update(std::vector<std::shared_ptr<Entity>> shapes)
{
    for (std::vector<std::shared_ptr<Entity>>::iterator iter = shapes.begin() ; iter != shapes.end(); ++iter)
    {

    }
}
