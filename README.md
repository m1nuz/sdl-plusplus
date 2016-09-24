# sdl-plusplus
Pure C++ wrapper for SDL2

[![Build Status](https://travis-ci.org/m1nuz/sdl-plusplus.svg?branch=master)](https://travis-ci.org/m1nuz/sdl-plusplus)
[![license](https://img.shields.io/github/license/mashape/apistatus.svg?maxAge=2592000?style=flat-square)]()

## Usage:
```c++
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

```
