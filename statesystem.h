#ifndef STATESYSTEM_H
#define STATESYSTEM_H

class StateSystem
{
public:
    // Constructor
    StateSystem () {};

    virtual void Init() = 0;
    virtual void Cleanup() = 0;

    virtual void Pause() = 0;
    virtual void Resume() = 0;

    virtual void Event() = 0;
//    virtual void Event(AppEngine& App) = 0;
//    virtual void Update(AppEngine& App) = 0;
//    virtual void Draw(AppEngine& App) = 0;
};

#endif // STATESYSTEM_H
