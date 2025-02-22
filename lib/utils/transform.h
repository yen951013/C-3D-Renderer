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

Matrix4x4 _3DR_zeroMatrix4x4();
Matrix4x4 _3DR_rotationMatrix4x4_X(float theta);
Matrix4x4 _3DR_rotationMatrix4x4_Y(float theta);
Matrix4x4 _3DR_rotationMatrix4x4_Z(float theta);
Matrix4x4 _3DR_projectionMatrix4x4(float nearPlane, float farPlane, float fovDegree, float aspect);
Matrix4x4 _3DR_viewportTransformMatrix4x4(int screenWidth, int screenHeight);

Matrix4x4 _3DR_multiplyMatrix4x4(Matrix4x4 *A, Matrix4x4 *B);

static inline float degToRad(int angleInDegrees);

void _3DR_transformVertices(Vec4 *vertices, int vertexCount, Vec4 *transformedVertices, Matrix4x4 *transformMatrix);
void _3DR_normalizeVertices(Vec4 *vertices, int vertexCount, Vec4 *normalizedVertices);

#endif  // _3DR_TRANSFORM_H_