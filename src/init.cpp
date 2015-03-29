#define SDL_PLUSPLUS_INIT
#include <sdl/sdl>

#include <SDL2/SDL.h>

#define LOG(...) fprintf(stdout, __VA_ARGS__)

namespace sdl
{
    namespace detail
    {
        extern _Init init;

        _Init::_Init()
        {
            SDL_Init(SDL_INIT_EVERYTHING);

            LOG("%s\n", "SDL init");
        }

        _Init::~_Init()
        {
            LOG("%s\n", "SDL quit");

            SDL_Quit();
        }
    } // namespace detail
} // namespace sdl
