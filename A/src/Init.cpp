#include "Init.hpp"

#include <SDL3/SDL.h>
#include <SDL3/SDL_mixer.h>

#include <cassert>

namespace ProjectA
{
    bool Init()
    {
        int r_SDLInit = SDL_Init(SDL_INIT_EVERYTHING);
        assert(r_SDLInit == 0);

        int r_SDLMixerInit = Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
        assert(r_SDLMixerInit == 0);

        return (r_SDLInit == r_SDLMixerInit == 0);
    }
    
    void Deinit()
    {   
        SDL_Quit();
        Mix_CloseAudio();
    }
}