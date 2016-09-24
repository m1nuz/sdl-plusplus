#include <cstdlib>
#include <sdl/sdl>

int main(int argc, char *argv[]) {
    sdl::window window(argc, argv);
    window.at(0, 0)
          .across(400, 400)
          .named("Simple window")
          .create();

    sdl::renderer renderer(window);
    renderer.accelerated()
            .create();

    sdl::event ev;
    ev.on_quit([]() {
        return false;
    });

    while (ev.poll()) {
        renderer.clear()
                .present();
    }

    return 0;
}
