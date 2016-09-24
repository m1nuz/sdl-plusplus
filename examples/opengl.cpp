#include <cstdlib>
#include <sdl/sdl>
#include <GL/gl.h>

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    sdl::window window(argc, argv);
    window.at(0, 0)
          .across(400, 400)
          .named("Opengl window")
          .with_opengl()
          .create();

    sdl::graphic_context gc(window);
    gc.version(4, 0)
      .with_forward_context()
      .with_debug_context()
      .with_core_profile()
      .create();

    std::string version(reinterpret_cast<const char*>(glGetString(GL_VERSION)));
    std::cout << "GL version: " << version << std::endl;

    sdl::event ev;
    ev.on_quit([]() {
        return false;
    });

    while (ev.poll()) {
        glClearColor(1, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        window.swap_buffers();
    }

    return EXIT_FAILURE;
}
