#ifndef _3DR_MATRIX_H_
#define _3DR_MATRIX_H_

#include <math.h>
#define M_PI 3.14159265358979323846

typedef struct Matrix4x4 {
    float m[16];
} Matrix4x4;

Matrix4x4 _3DR_Mat_newZeroMatrix4x4();
Matrix4x4 _3DR_Mat_newTranslationMat4x4(float tx, float ty, float tz);
Matrix4x4 _3DR_Mat_newRotationMat4x4_X(float theta);
Matrix4x4 _3DR_Mat_newRotationMat4x4_Y(float theta);
Matrix4x4 _3DR_Mat_newRotationMat4x4_Z(float theta);
Matrix4x4 _3DR_Mat_newProjectionMat4x4(float nearPlane, float farPlane, float fovDegree, float aspect);
Matrix4x4 _3DR_Mat_newViewportTransformMat4x4(int screenWidth, int screenHeight);

Matrix4x4 _3DR_Mat_multiplyMatrix4x4(Matrix4x4 *A, Matrix4x4 *B);

static inline float degToRad(int angleInDegrees);

#endif  // _3DR_MATRIX_H_