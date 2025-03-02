#include <stdio.h>
#include <stdint.h>
#include "config.h"

int main() {
    _3DR_FrameBuffer frameBuffer = _3DR_FB_newFrameBuffer(_3DR_SCREEN_WIDTH, _3DR_SCREEN_HEIGHT);
    _3DR_init(_3DR_SCREEN_WIDTH, _3DR_SCREEN_HEIGHT);

    _3DR_Model model = _3DR_Model_loadModel("models/cube.obj", (Vec3){0, 0, 0});

    Matrix4x4 projectionMat = _3DR_Mat_newProjectionMat4x4(_3DR_NEAR_PLANE, _3DR_FAR_PLANE, _3DR_FOV_DEGREE, _3DR_ASPECT);
    Matrix4x4 viewportTransformMat = _3DR_Mat_newViewportTransformMat4x4(_3DR_SCREEN_WIDTH, _3DR_SCREEN_HEIGHT);

    while (_3DR_isRunning()) {
        _3DR_eventHandler();
        
        // transform model

        SDL_Delay(100);
    }

    // _3DR_drawTriangle(&frameBuffer, 100, 100, 500, 150, 200, 350, 0xFF1111EE);

    _3DR_render(&frameBuffer);

    SDL_Delay(4000);
    _3DR_quit();

    return 0;
}