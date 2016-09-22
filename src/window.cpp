#define SDL_PLUSPLUS_INIT
#include <sdl/sdl>

#include <SDL2/SDL.h>

#define LOG(...) fprintf(stdout, __VA_ARGS__)

namespace sdl {
    window::window(int argc, char* argv[]) :
        id(0), x(0), y(0), w(0), h(0), flags(0) {
    }

    window::~window() {
        if (id) {
            LOG("Destroy window %p\n", id);
            SDL_DestroyWindow(static_cast<SDL_Window*>(id));
        }

        id = nullptr;
    }

    window& window::at(const int _x, const int _y) {
        x = _x, y = _y;
        return *this;
    }

    window& window::across(const int _w, const int _h) {
        w = _w, h = _h;
        return *this;
    }

    window& window::named(const std::string& _title) {
        if (!id)
            title_text = _title;
        else
            SDL_SetWindowTitle(static_cast<SDL_Window*>(id), title_text.c_str());
        return *this;
    }

    window& window::show() {
        if (!id)
            flags |= SDL_WINDOW_SHOWN;
        else
        {
            flags |= SDL_WINDOW_SHOWN;
            SDL_ShowWindow(static_cast<SDL_Window*>(id));
        }
        return *this;
    }

    window &window::with_opengl() {
        flags |= SDL_WINDOW_OPENGL;
        return *this;
    }

    window& window::create() {
        id = SDL_CreateWindow(title_text.c_str(), x, y, w, h, flags);
        LOG("Create window %p\n", id);
        return *this;
    }

    void window::swap_buffers() {
        SDL_GL_SwapWindow(static_cast<SDL_Window*>(id));
    }
} // namespace sdl
