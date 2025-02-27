#ifndef _3DR_CONFIG_H
#define _3DR_CONFIG_H

#define _3DR_SCREEN_WIDTH 640
#define _3DR_SCREEN_HEIGHT 480

#define _3DR_NEAR_PLANE 0.1
#define _3DR_FAR_PLANE 100
#define _3DR_FOV_DEGREE 60
#define _3DR_ASPECT (_3DR_SCREEN_WIDTH / _3DR_SCREEN_HEIGHT)

#include "lib/frame_buffer/frame_buffer.h"
#include "lib/graphical/triangle_rasterization.h"
#include "lib/graphical/transform.h"
#include "lib/utils/vector.h"
#include "lib/model/model.h"
#include "lib/model/obj_parser.h"

#ifdef _3DR_PLATFORM_SDL
    #include "platform/sdl_implement.h"

    #define _3DR_init _3DR_PLATFORM_SDL_init
    #define _3DR_isRunning _3DR_PLATFORM_SDL_isRunning
    #define _3DR_render _3DR_PLATFORM_SDL_render
    #define _3DR_quit _3DR_PLATFORM_SDL_quit
#endif    // _3DR_PLATFORM_SDL

#endif  // _3DR_CONFIG_H