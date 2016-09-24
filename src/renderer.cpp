#include <sdl/window>
#include <sdl/renderer>

#include <SDL2/SDL_render.h>

#define LOG(...) fprintf(stdout, __VA_ARGS__)

namespace sdl {
    namespace detail {
        renderer::renderer(const window &_w):
            id(0), flags(0), w(_w) {
        }

        renderer::~renderer() {
            LOG("Destroy renderer %p\n", id);
            SDL_DestroyRenderer(static_cast<SDL_Renderer*>(id));
        }

        renderer &renderer::software() {
            flags |= SDL_RENDERER_SOFTWARE;
            return *this;
        }

        renderer& renderer::accelerated() {
            flags |= SDL_RENDERER_ACCELERATED;
            return *this;
        }

        renderer& renderer::vsync() {
            flags |= SDL_RENDERER_PRESENTVSYNC;
            return *this;
        }

        renderer& renderer::target_texture() {
            flags |= SDL_RENDERER_TARGETTEXTURE;
            return *this;
        }

        renderer& renderer::create() {
            id = SDL_CreateRenderer(static_cast<SDL_Window*>(w.id), -1, flags);
            LOG("Create renderer %p\n", id);
            return *this;
        }

        renderer &renderer::clear() {
            SDL_RenderClear(static_cast<SDL_Renderer*>(id));
            return *this;
        }

        renderer &renderer::present() {
            SDL_RenderPresent(static_cast<SDL_Renderer*>(id));
            return *this;
        }
    } // namespace detail
} // namespace sdl
