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

    sdl::event e;

    while (true) {
        while(sdl::poll(e)) {
            if (e == sdl::event::QUIT)
                return EXIT_SUCCESS;
        }

        renderer.clear()
                .present();
    }

    return EXIT_FAILURE;
}
