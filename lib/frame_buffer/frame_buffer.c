#include "frame_buffer.h"

_3DR_FrameBuffer _3DR_newFrameBuffer(size_t width, size_t height) {
    _3DR_FrameBuffer frameBuffer;
    frameBuffer.pixels = malloc(width * height * sizeof(uint32_t));
    frameBuffer.width = width;
    frameBuffer.height = height;

    return frameBuffer;
}