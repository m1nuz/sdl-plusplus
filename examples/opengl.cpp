#include <cstdlib>
#include <sdl/sdl>
#include <GL/gl.h>

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    sdl::window w("Test", 0, 0, 400, 400, sdl::window::OPENGL);
    sdl::graphic_context gc(&w);
    sdl::event e;

    std::string version(reinterpret_cast<const char*>(glGetString(GL_VERSION)));
    std::cout << "GL version: " << version << std::endl;

    while (1) {
        while(sdl::poll(e))
        {
            if (e == sdl::event::QUIT)
                return EXIT_SUCCESS;
        }

        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        sdl::window::swap_buffers(w);
    }

    return EXIT_FAILURE;
}
