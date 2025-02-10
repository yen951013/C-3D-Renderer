#include "sdl_implement.h"

int _3DR_running = 0;

struct SDL_state {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
} _3DR_SDL_state;

int _3DR_PLATFORM_SDL_init(size_t width, size_t height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL Init Failed: %s\n", SDL_GetError());
        return -1;
    }

    _3DR_SDL_state.window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                       width, height, SDL_WINDOW_SHOWN);
    if (_3DR_SDL_state.window == NULL) {
        return -1;
    }

    _3DR_SDL_state.renderer = SDL_CreateRenderer(_3DR_SDL_state.window, -1, SDL_RENDERER_ACCELERATED);
    if (_3DR_SDL_state.renderer == NULL) {
        return -1;
    }

    _3DR_SDL_state.texture = SDL_CreateTexture(_3DR_SDL_state.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);

    _3DR_running = 1;
    return 1;
}

int _3DR_PLATFORM_SDL_isRunning() {
    return _3DR_running;
}

void _3DR_PLATFORM_SDL_render(_3DR_FrameBuffer *frameBuffer) {
    void* texturePixels;
    int pitch;
    SDL_LockTexture(_3DR_SDL_state.texture, NULL, &texturePixels, &pitch);

    memcpy(texturePixels, frameBuffer->pixels, frameBuffer->width * frameBuffer->height * sizeof(Uint32));

    // 解鎖紋理
    SDL_UnlockTexture(_3DR_SDL_state.texture);

    // 渲染紋理到畫面
    SDL_RenderCopy(_3DR_SDL_state.renderer, _3DR_SDL_state.texture, NULL, NULL);
    SDL_RenderPresent(_3DR_SDL_state.renderer);
}

void _3DR_PLATFORM_SDL_quit() {
    SDL_DestroyTexture(_3DR_SDL_state.texture);
    SDL_DestroyRenderer(_3DR_SDL_state.renderer);
    SDL_DestroyWindow(_3DR_SDL_state.window);
    SDL_Quit();
}