#ifndef _3DR_MODEL_H
#define _3DR_MODEL_H

#include <stdint.h>
#include <stdbool.h>
#include "../../config.h"
#include "../graphical/transform.h"
#include "../utils/vector.h"
#include "../utils/matrix.h"
#include "obj_parser.h"

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

    Vec4 *transformedVertices; // 變換後的頂點

    bool update;
    Vec3 position;
    float thetaX, thetaY, thetaZ;
    Matrix4x4 modelTransform;
} _3DR_Model;

typedef struct _3DR_SceneModels {
    int count;
    _3DR_Model models[MAX_MODELS];
} _3DR_SceneModels;

void _3DR_addModelToScene(_3DR_SceneModels *sceneModels, const char *filePath, Vec3 position, Vec3 rotation);

#endif  // _3DR_MODEL_H