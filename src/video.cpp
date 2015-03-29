#define SDL_PLUSPLUS_INIT
#include <sdl/sdl>

#include <SDL2/SDL_video.h>

#define LOG(...) fprintf(stdout, __VA_ARGS__)

namespace sdl
{
    void set_attribute(const graphic_attributes &attrs, unsigned int attr, int value)
    {

    }

    int get_attribute(const graphic_attributes &attrs, unsigned int attr)
    {
        return 0;
    }

    graphic_attributes::graphic_attributes()
    {
        memset(attributes, 0, sizeof(attributes));
    }

    graphic_attributes::~graphic_attributes()
    {
        memset(attributes, 0, sizeof(attributes));
    }

    graphic_context::graphic_context(const window *w):
        id(SDL_GL_CreateContext(static_cast<SDL_Window*>(w->id)))
    {
        LOG("Create graphic context %p\n", id);
    }

    graphic_context::~graphic_context()
    {
       LOG("Destroy graphic context %p\n", id);

       SDL_GL_DeleteContext(id);
    }
} // namespace sdl
