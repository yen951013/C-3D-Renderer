#ifndef _3DR_VECTOR_H_
#define _3DR_VECTOR_H_

#include <math.h>

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

Vec3 _3DR_Vec3_crossProduct(Vec3 v1, Vec3 v2);
float _3DR_Vec3_dotProduct(Vec3 v1, Vec3 v2);
Vec3 _3DR_Vec3_normalize(Vec3 v);

#endif  // _3DR_VECTOR_H_