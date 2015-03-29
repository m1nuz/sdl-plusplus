#define SDL_PLUSPLUS_INIT
#include <sdl/sdl>

#include <SDL2/SDL.h>

#define LOG(...) fprintf(stdout, __VA_ARGS__)

namespace sdl
{
    static uint32_t window_get_sdl_flags(unsigned int flags)
    {
        uint32_t out = 0;

        if (flags & window::FULLSCREEN)
            out |= SDL_WINDOW_FULLSCREEN;

        if (flags & window::FULLSCREEN_DESKTOP)
            out |= SDL_WINDOW_FULLSCREEN_DESKTOP;

        if (flags & window::OPENGL)
            out |= SDL_WINDOW_OPENGL;

        if (flags & window::SHOWN)
            out |= SDL_WINDOW_SHOWN;

        if (flags & window::HIDDEN)
            out |= SDL_WINDOW_HIDDEN;

        if (flags & window::BORDERLESS)
            out |= SDL_WINDOW_BORDERLESS;

        return out;
    }

    window::window(const char *title, int x, int y, int w, int h, unsigned int flags):
        id(SDL_CreateWindow(title, x, y, w, h, window_get_sdl_flags(flags)))
    {
        LOG("Create window %p\n", id);
    }

    window::~window()
    {
        LOG("Destroy window %p\n", id);

        SDL_DestroyWindow(static_cast<SDL_Window*>(id));
        id = nullptr;
    }

    void window::set_title(window &w, const char *title)
    {
        SDL_SetWindowTitle(static_cast<SDL_Window*>(w.id), title);
    }

    const char *window::get_title(const window &w)
    {
        return SDL_GetWindowTitle(static_cast<SDL_Window*>(w.id));
    }

    void window::swap_buffers(window &w)
    {
        SDL_GL_SwapWindow(static_cast<SDL_Window*>(w.id));
    }   
} // namespace sdl
