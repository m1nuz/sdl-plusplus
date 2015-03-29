#include <cstdlib>
#include <sdl/sdl>

int main(int argc, char *argv[]) {
    sdl::window window("Test", 0, 0, 400, 400, 0);
    sdl::renderer renderer(&window, sdl::renderer::ACCELERATED);

    sdl::window::set_title(window, "Simple");

    sdl::event e;

    while (1) {
        while(sdl::poll(e))
        {
            if (e == sdl::event::QUIT)
                return EXIT_SUCCESS;
        }

        sdl::renderer::clear(renderer);
        sdl::renderer::present(renderer);
    }

    return EXIT_FAILURE;
}
