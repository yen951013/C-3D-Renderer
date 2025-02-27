#ifndef _3DR_VECTOR_H_
#define _3DR_VECTOR_H_

#include <math.h>

typedef struct Vec3 {
    float x, y, z;
} Vec3;

Vec3 Vec3_crossProduct(Vec3 v1, Vec3 v2);
float Vec3_dotProduct(Vec3 v1, Vec3 v2);
Vec3 Vec3_normalize(Vec3 v);

#endif  // _3DR_VECTOR_H_