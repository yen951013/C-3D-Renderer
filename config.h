#ifndef _3DR_CONFIG_H
#define _3DR_CONFIG_H

#define _3DR_SCREEN_WIDTH 640
#define _3DR_SCREEN_HEIGHT 480

#include "lib/frame_buffer/frame_buffer.h"
#include "lib/graphical/triangle_rasterization.h"


#ifdef _3DR_PLATFORM_SDL
    #include "platform/sdl_implement.h"

    #define _3DR_init _3DR_PLATFORM_SDL_init
    #define _3DR_isRunning _3DR_PLATFORM_SDL_isRunning
    #define _3DR_render _3DR_PLATFORM_SDL_render
    #define _3DR_quit _3DR_PLATFORM_SDL_quit
#endif    // _3DR_PLATFORM_SDL

#endif  // _3DR_CONFIG_H