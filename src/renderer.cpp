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

        renderer& renderer::clear() {
            SDL_RenderClear(static_cast<SDL_Renderer*>(id));
            return *this;
        }

        renderer& renderer::present() {
            SDL_RenderPresent(static_cast<SDL_Renderer*>(id));
            return *this;
        }

        renderer& renderer::draw_color(const color &c) {
            SDL_SetRenderDrawColor(static_cast<SDL_Renderer*>(id), c.r, c.g, c.b, c.a);
            return *this;
        }

        renderer& renderer::draw_point(const point &pt) {
            SDL_RenderDrawPoint(static_cast<SDL_Renderer*>(id), pt.x, pt.y);
            return *this;
        }

        renderer& renderer::draw_line(const point &pt1, const point &pt2) {
            SDL_RenderDrawLine(static_cast<SDL_Renderer*>(id), pt1.x, pt1.y, pt2.x, pt2.y);
            return *this;
        }

        renderer& renderer::draw_rect(const rect &rc, const bool fill) {
            if (fill)
                SDL_RenderFillRect(static_cast<SDL_Renderer*>(id), reinterpret_cast<const SDL_Rect *>(&rc));
            else
                SDL_RenderDrawRect(static_cast<SDL_Renderer*>(id), reinterpret_cast<const SDL_Rect *>(&rc));
            return *this;
        }
    } // namespace detail
} // namespace sdl
