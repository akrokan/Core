#include "appengine.h"

int main(void)
{
    // Instances
    AppEngine App;

    // Variable
    std::vector<std::shared_ptr<Entity>> shapes;

    // Initialize the application engine
    App.Init();

    // Main loop
    while (App.Running())
    {
        App.Event(shapes, &App);
        App.Update(shapes);
        App.Draw(shapes);
    }

    // Bye
    return 0;
}
