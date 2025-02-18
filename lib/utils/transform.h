#ifndef _3DR_TRANSFORM_H_
#define _3DR_TRANSFORM_H_

#include <math.h>
#define M_PI 3.14159265358979323846

typedef struct Matrix4x4 {
    float m[16];
} Matrix4x4;

typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

Matrix4x4 zeroMatrix4x4();
Matrix4x4 rotationMatrix4x4x(float theta);
Matrix4x4 rotationMatrix4x4y(float theta);
Matrix4x4 rotationMatrix4x4z(float theta);
Matrix4x4 projectionMatrix4x4(float nearPlane, float farPlane, float fovDegree, float aspect);

void multiplyMatrix4x4(Matrix4x4 *A, Matrix4x4 *B, Matrix4x4 *result);

static inline float degToRad(int angleInDegrees);


#endif  // _3DR_TRANSFORM_H_