#include "SDL3/SDL.h"
#include "SDL3/SDL_mixer.h"
#include "box2d/box2d.h"
#include "stb_image.h"

#include <iostream>

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* Window = SDL_CreateWindow("Test", 700, 360, 0);
    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) != 0)
    {
        std::cout << "Failed to initialize Mixer: " << Mix_GetError() << "\n";
    }

    Mix_Chunk* sound = Mix_LoadWAV("resource/sound/message-pop-sound.wav");

    if(!sound)
    {
        std::cout << "Failed to load the given WAV- file\n";
    }

    int channel = Mix_PlayChannel(-1, sound, 0);
    // while(Mix_Playing(channel) != 0);

    SDL_Delay(5000);
    

    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);
    
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);
    
    b2Body* groundBody = world.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    
    groundBox.SetAsBox(50.0f, 10.0f);

    world.DestroyBody(groundBody);

    Mix_FreeChunk(sound);
    Mix_CloseAudio();
    SDL_DestroyWindow(Window);
    SDL_Quit();

    return (0);
}