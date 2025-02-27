#include <stdio.h>
#include <stdint.h>
#include "config.h"

int main() {
    _3DR_FrameBuffer frameBuffer = _3DR_newFrameBuffer(_3DR_SCREEN_WIDTH, _3DR_SCREEN_HEIGHT);
    _3DR_init(_3DR_SCREEN_WIDTH, _3DR_SCREEN_HEIGHT);


    _3DR_Model model = _3DR_loadModel("models/cube.obj");
    //print vertices
    for (int i = 0; i < model.v_count; i++) {
        printf("v: %f, %f, %f\n", model.vertices[i].x, model.vertices[i].y, model.vertices[i].z);
    }

    // while (_3DR_isRunning()) {
    // //     //_3DR_eventHandler();
    //     SDL_Delay(100);
    // }

    

    _3DR_drawTriangle(&frameBuffer, 100, 100, 500, 150, 200, 350, 0xFF1111EE);

    _3DR_render(&frameBuffer);

    SDL_Delay(4000);
    _3DR_quit();

    return 0;
}