#include "SDL3/SDL.h"
#include "box2d/box2d.h"

#include <iostream>

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* Window = SDL_CreateWindow("Test", 700, 360, 0);
    
    SDL_Delay(5000);

    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);
    
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);
    
    b2Body* groundBody = world.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    
    groundBox.SetAsBox(50.0f, 10.0f);

    SDL_DestroyWindow(Window);
    SDL_Quit();

    return (0);
}