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
        renderer.draw_color({0, 0, 0, 0})
                .clear()
                .draw_color({255, 0, 0, 0})
                .draw_point({200, 200})
                .draw_line({0, 0}, {100, 100})
                .draw_rect({300, 300, 50, 50}, true)
                .present();
    }

    return 0;
}
