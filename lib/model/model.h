#ifndef _3DR_MODEL_H
#define _3DR_MODEL_H

#include <stdint.h>
#include <stdbool.h>
#include "../graphical/transform.h"
#include "../utils/vector.h"

typedef struct _3DR_Face {
    int p1, p2, p3; // 逆時針
    int n1, n2, n3; // 先忽略 n2, n3
} _3DR_Face;

typedef struct _3DR_Model {
    int v_count, vt_count, vn_count, f_count;
    Vec3 *vertices;
    bool *isVisible;
    Vec3 *normals;
    _3DR_Face *faces;
} _3DR_Model;

#endif  // _3DR_MODEL_H