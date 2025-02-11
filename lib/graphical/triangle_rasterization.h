#ifndef _3DR_TRIANGLE_RASTERIZATION_H
#define _3DR_TRIANGLE_RASTERIZATION_H

#include <stdint.h>
#include "../frame_buffer/frame_buffer.h"

void _3DR_drawTriangle(_3DR_FrameBuffer *frameBuffer, int x1, int y1, int x2, int y2, int x3, int y3, uint32_t color);

static inline int minInTwoInt(int a, int b);
static inline int maxInTwoInt(int a, int b);
static inline int minInThreeInt(int a, int b, int c);
static inline int maxInThreeInt(int a, int b, int c);

#endif  // _3DR_TRIANGLE_RASTERIZATION_H