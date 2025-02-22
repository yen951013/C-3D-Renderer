#ifndef _3DR_FRAME_BUFFER_H
#define _3DR_FRAME_BUFFER_H

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct _3DR_FrameBuffer {
    uint32_t *pixels;
    size_t width;
    size_t height;
} _3DR_FrameBuffer;

_3DR_FrameBuffer _3DR_newFrameBuffer(size_t width, size_t height);

void _3DR_drawRectangle(_3DR_FrameBuffer *frameBuffer, int x, int y, int width, int height, uint32_t color);

#endif  // _3DR_FRAME_BUFFER_H