#include "triangle_rasterization.h"

static inline int edgeFunction(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

void _3DR_drawTriangle(_3DR_FrameBuffer *frameBuffer, int x1, int y1, int x2, int y2, int x3, int y3, uint32_t color) {
    // 找出邊界
    int minX = maxInTwoInt(0                    , minInThreeInt(x1, x2, x3));
    int maxX = minInTwoInt(frameBuffer->width - 1 , maxInThreeInt(x1, x2, x3));
    int minY = maxInTwoInt(0                      , minInThreeInt(y1, y2, y3));
    int maxY = minInTwoInt(frameBuffer->height - 1, maxInThreeInt(y1, y2, y3));

    int ABC = edgeFunction(x1, y1, x2, y2, x3, y3);
    if (ABC < 0) {
        return;
    }

    for (int y = minY; y <= maxY; y++) {
        for (int x = minX; x <= maxX; x++) {
            // 判斷點是否在三角形內
            int ABP = edgeFunction(x1, y1, x2, y2, x, y);
            int BCP = edgeFunction(x2, y2, x3, y3, x, y);
            int CAP = edgeFunction(x3, y3, x1, y1, x, y);

            if (ABP == 0 || BCP == 0 || CAP == 0) {
                frameBuffer->pixels[y * frameBuffer->width + x] = 0xFF666666;
            }else if (ABP >= 0 && BCP >= 0 && CAP >= 0) {
                // 在三角形內
                frameBuffer->pixels[y * frameBuffer->width + x] = color;
            }
        }
    }

}

static inline int minInTwoInt(int a, int b) {
    return a < b ? a : b;
}
static inline int maxInTwoInt(int a, int b) {
    return a > b ? a : b;
}
static inline int minInThreeInt(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}
static inline int maxInThreeInt(int a, int b, int c) {
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}