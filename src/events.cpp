#include <sdl/event>

#include <SDL2/SDL_events.h>

#define LOG(...) fprintf(stdout, __VA_ARGS__)

namespace sdl {
    namespace detail {
        event& event::on_quit(std::function<bool ()> cb) {
            quit_cb = cb;
        }

        bool event::poll() const {
            SDL_Event ev;
            while (SDL_PollEvent(&ev)) {
                switch (ev.type) {
                case SDL_QUIT:
                    if (quit_cb)
                        if(!quit_cb())
                            return false;
                    break;
                }
            }

            return true;
        }
    } // namespace detail
} // namespace sdl
