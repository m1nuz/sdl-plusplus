#define SDL_PLUSPLUS_INIT
#include <sdl/sdl>

#include <SDL2/SDL.h>

#define LOG(...) fprintf(stdout, __VA_ARGS__)

namespace sdl {
    namespace detail {
        extern _init init;

        _init::_init() {
            SDL_Init(SDL_INIT_EVERYTHING);

            LOG("%s\n", "SDL init");
        }

        _init::~_init() {
            LOG("%s\n", "SDL quit");

            SDL_Quit();
        }
    } // namespace detail
} // namespace sdl
