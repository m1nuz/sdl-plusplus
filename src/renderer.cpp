#define SDL_PLUSPLUS_INIT
#include <sdl/sdl>

#include <SDL2/SDL_render.h>

#define LOG(...) fprintf(stdout, __VA_ARGS__)

namespace sdl
{
    inline uint32_t renderer_get_sdl_flags(unsigned int flags)
    {
        uint32_t out = 0;

        if (flags & renderer::SOFTWARE)
            out |= SDL_RENDERER_SOFTWARE;

        if (flags & renderer::ACCELERATED)
            out |= SDL_RENDERER_ACCELERATED;

        if (flags & renderer::PRESENT_VSYNC)
            out |= SDL_RENDERER_PRESENTVSYNC;

        if (flags & renderer::TARGET_TEXTURE)
            out |= SDL_RENDERER_TARGETTEXTURE;

        return out;
    }

    renderer::renderer(const window *w, unsigned int flags):
        id(SDL_CreateRenderer(static_cast<SDL_Window*>(w->id), -1, renderer_get_sdl_flags(flags)))
    {
        LOG("Create renderer %p\n", id);
    }

    renderer::~renderer()
    {
        LOG("Destroy renderer %p\n", id);

        SDL_DestroyRenderer(static_cast<SDL_Renderer*>(id));
    }

    void renderer::clear(const renderer &r)
    {
        SDL_RenderClear(static_cast<SDL_Renderer*>(r.id));
    }

    void renderer::present(const renderer &r)
    {
        SDL_RenderPresent(static_cast<SDL_Renderer*>(r.id));
    }
} // namespace sdl
