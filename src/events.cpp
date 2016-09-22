#define SDL_PLUSPLUS_INIT
#include <sdl/sdl>

#include <SDL2/SDL_events.h>

#define LOG(...) fprintf(stdout, __VA_ARGS__)

namespace sdl {
    bool event::operator ==(int type) {
        return this->type == type;
    }

    int poll(event &e) {
        SDL_Event evnt;
        int ret = SDL_PollEvent(&evnt);

        switch (evnt.type) {
        case SDL_QUIT:
            e.type = event::QUIT;
            break;
        }

        return ret;
    }
} // namespace sdl
