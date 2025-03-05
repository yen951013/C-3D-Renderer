#include "frame_buffer.h"

void _3DR_FB_clear(_3DR_FrameBuffer *frameBuffer) {
    for (int i = 0; i < frameBuffer->width * frameBuffer->height; i++) {
        frameBuffer->pixels[i] = 0;
    }
}

_3DR_FrameBuffer _3DR_FB_newFrameBuffer(size_t width, size_t height) {
    _3DR_FrameBuffer frameBuffer;
    frameBuffer.pixels = malloc(width * height * sizeof(uint32_t));
    frameBuffer.width = width;
    frameBuffer.height = height;

    return frameBuffer;
}

void _3DR_FB_drawRectangle(_3DR_FrameBuffer *frameBuffer, int x, int y, int width, int height, uint32_t color) {
    if (x < 0 || y < 0 || x + width > (int)frameBuffer->width || y + height > (int)frameBuffer->height) {
        return;
    }
    for (int i = x; i < x + width; i++) {
        for (int j = y; j < y + height; j++) {
            frameBuffer->pixels[j * frameBuffer->width + i] = color;
        }
    }
}