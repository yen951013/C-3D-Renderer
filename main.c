#include "config.h"
#include <stdint.h>

int main() {
    _3DR_FrameBuffer frameBuffer = _3DR_newFrameBuffer(_3DR_SCREEN_WIDTH, _3DR_SCREEN_HEIGHT);
    _3DR_init(_3DR_SCREEN_WIDTH, _3DR_SCREEN_HEIGHT);

    while (_3DR_isRunning()) {
        //_3DR_eventHandler();
        _3DR_render(&frameBuffer);
        SDL_Delay(1000);
        _3DR_quit();
        break;
    }

    return 0;
}