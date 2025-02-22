#include <stdio.h>
#include <stdint.h>
#include "config.h"

Vec4 vertices[1000];

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                vertices[i * 100 + j * 10 + k].x = (i - 4.5);
                vertices[i * 100 + j * 10 + k].y = (j - 4.5);
                vertices[i * 100 + j * 10 + k].z = (k - 4.5) + 18;
                vertices[i * 100 + j * 10 + k].w = 1;
            }
        }
    }

    _3DR_FrameBuffer frameBuffer = _3DR_newFrameBuffer(_3DR_SCREEN_WIDTH, _3DR_SCREEN_HEIGHT);
    _3DR_init(_3DR_SCREEN_WIDTH, _3DR_SCREEN_HEIGHT);

    Matrix4x4 projectionMatrix = _3DR_projectionMatrix4x4(_3DR_NEAR_PLANE, _3DR_FAR_PLANE, _3DR_FOV_DEGREE, _3DR_ASPECT);
    Matrix4x4 viewportTransformMatrix = _3DR_viewportTransformMatrix4x4(_3DR_SCREEN_WIDTH, _3DR_SCREEN_HEIGHT);

    // multiply nsformation matrices
    Matrix4x4 transformMatrix = {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    transformMatrix = _3DR_multiplyMatrix4x4(&projectionMatrix, &transformMatrix);

    // transform verticies
    Vec4 transformedVertices[1000];
    _3DR_transformVertices(vertices, 1000, transformedVertices, &transformMatrix);
    
    // normalize
    Vec4 normalizedVertices[1000];
    _3DR_normalizeVertices(transformedVertices, 1000, normalizedVertices);

    // NDC coord to screen coord
    Vec4 ScreenVertices[1000];
    _3DR_transformVertices(normalizedVertices, 1000, ScreenVertices, &viewportTransformMatrix);

    for (int i = 0; i < 1000; i++) {
        // draw rectangle
        printf("%f %f %f %f\n", ScreenVertices[i].x, ScreenVertices[i].y, ScreenVertices[i].z, ScreenVertices[i].w);
        _3DR_drawRectangle(&frameBuffer, ScreenVertices[i].x - 2, ScreenVertices[i].y - 2, 4, 4, 0xFF1111EE);
    }

    _3DR_render(&frameBuffer);

    // while (_3DR_isRunning()) {
    // //     //_3DR_eventHandler();
    //     SDL_Delay(100);
    // }

    

    // _3DR_drawTriangle(&frameBuffer, 100, 100, 500, 150, 200, 350, 0xFF1111EE);


    SDL_Delay(4000);
    _3DR_quit();

    return 0;
}