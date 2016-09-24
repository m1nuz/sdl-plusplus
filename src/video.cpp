#define SDL_PLUSPLUS_INIT
#include <sdl/sdl>

#include <SDL2/SDL_video.h>

#define LOG(...) fprintf(stdout, __VA_ARGS__)

namespace sdl {
    graphic_context::graphic_context(const window &_w):
        id(0), context_flags(0), w(_w) {
        memset(attributes, 0, sizeof(attributes));
    }

    graphic_context::~graphic_context() {
       LOG("Destroy graphic context %p\n", id);

       SDL_GL_DeleteContext(id);
    }

    graphic_context& graphic_context::doublebuffered() {
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        return *this;
    }

    graphic_context &graphic_context::version(const int major, const int minor) {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
        return *this;
    }

    graphic_context& graphic_context::with_core_profile() {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        return *this;
    }

    graphic_context& graphic_context::with_forward_context() {
        context_flags |= SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG;
        return *this;
    }

    graphic_context &graphic_context::with_debug_context() {
        context_flags |= SDL_GL_CONTEXT_DEBUG_FLAG;
        return *this;
    }

    graphic_context& graphic_context::create() {
        LOG("Create graphic context %p\n", id);

        if (context_flags)
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, context_flags);

        id = SDL_GL_CreateContext(static_cast<SDL_Window*>(w.id));
        return *this;
    }
} // namespace sdl
