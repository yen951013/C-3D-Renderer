#ifndef _3DR_PLATFORM_SDL_IMPLEMENT_H
#define _3DR_PLATFORM_SDL_IMPLEMENT_H

#include <SDL2/SDL.h>
#include "../lib/frame_buffer/frame_buffer.h"

int _3DR_PLATFORM_SDL_init(size_t width, size_t height);
int _3DR_PLATFORM_SDL_isRunning();
void _3DR_PLATFORM_SDL_render(_3DR_FrameBuffer *frameBuffer);
void _3DR_PLATFORM_SDL_quit();


#endif  // _3DR_PLATFORM_SDL_IMPLEMENT_H