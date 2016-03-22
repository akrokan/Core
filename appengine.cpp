#include "appengine.h"

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
        auto shape = (*iter)->get<SpriteComponent>()->getSprite();
        shape.setPosition(sf::Vector2f((*iter)->get<PositionComponent>()->getX(), (*iter)->get<PositionComponent>()->getY()));

        window.draw(shape);
    }

    window.display();
}

void AppEngine::Event(std::vector<std::shared_ptr<Entity>> shapes, AppEngine *App)
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
                MenuState Menu(App, &window);
            }
            if (event.key.code == sf::Keyboard::Space)
            {
                PlayState Play(&window, App);
            }
        }
    }
}

void AppEngine::Init()
{
    window.create(sf::VideoMode(480, 480), "App");
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
