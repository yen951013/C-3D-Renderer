#include "matrix.h"

Matrix4x4 _3DR_Mat_newZeroMatrix4x4() {
    Matrix4x4 mat = {0};
    return mat;
}
Matrix4x4 _3DR_Mat_newRotationMat4x4_X(float theta) {
	Matrix4x4 mat = {0};  // 初始化為 0 矩陣
	
	float rad = degToRad(theta);  // 轉換為弧度
	float cosTheta = cosf(rad);
	float sinTheta = sinf(rad);
	
	// 1    0         0
	// 0 cosTheta -sinTheta
	// 0 sinTheta  cosTheta
	
	mat.m[0] = 1;  // X 坐標不變
	mat.m[5] = cosTheta;
	mat.m[6] = -sinTheta;
	mat.m[9] = sinTheta;
	mat.m[10] = cosTheta;
	mat.m[15] = 1;  // 齊次座標
	
	return mat;
}
Matrix4x4 _3DR_Mat_newRotationMat4x4_Y(float theta) {
	Matrix4x4 mat = {0};  // 初始化為 0 矩陣
	
	float rad = degToRad(theta);  // 轉換為弧度
	float cosTheta = cosf(rad);
	float sinTheta = sinf(rad);
	
	//  cosTheta 0 sinTheta
	//     0     1    0
	// -sinTheta 0 cosTheta
	
	mat.m[0] = cosTheta;
	mat.m[2] = sinTheta;
	mat.m[5] = 1;  // Y 坐標不變
	mat.m[8] = -sinTheta;
	mat.m[10] = cosTheta;
	mat.m[15] = 1;  // 齊次座標
	
	return mat;
}
Matrix4x4 _3DR_Mat_newRotationMat4x4_Z(float theta){
	Matrix4x4 mat = {0};  // 初始化為 0 矩陣
	
	float rad = degToRad(theta);  // 轉換為弧度
	float cosTheta = cosf(rad);
	float sinTheta = sinf(rad);
	
	// cosTheta -sinTheta 0
	// sinTheta  cosTheta 0
	//    0         0     1
	
	mat.m[0] = cosTheta;
	mat.m[1] = -sinTheta;
	mat.m[4] = sinTheta;
	mat.m[5] = cosTheta;
	mat.m[10] = 1;  // Z 坐標不變
	mat.m[15] = 1;  // 齊次座標
	
	return mat;}
Matrix4x4 _3DR_Mat_newProjectionMat4x4(float nearPlane, float farPlane, float fovDegree, float aspect) {
    Matrix4x4 mat = {0};

    float tanHalfFOV = tan(degToRad(fovDegree) / 2);
    mat.m[0] = 1 / (aspect * tanHalfFOV);
    mat.m[5] = 1 / tanHalfFOV;
    mat.m[10] = -(farPlane + nearPlane) / (farPlane - nearPlane);
    mat.m[11] = -2 * farPlane * nearPlane / (farPlane - nearPlane);
    mat.m[14] = -1;

    return mat;
}
Matrix4x4 _3DR_Mat_newViewportTransformMat4x4(int screenWidth, int screenHeight) {
    Matrix4x4 mat = {0};
	
    mat.m[0] = screenWidth / 2.0f;
	mat.m[3] = (screenWidth - 1) / 2.0f;
	mat.m[5] = -screenHeight / 2.0f;
	mat.m[7] = -(screenHeight - 1) / 2.0f + screenHeight;
	mat.m[10] = 1.0f;
	mat.m[15] = 1.0f;
	
    return mat;
}

Matrix4x4 _3DR_Mat_multiplyMatrix4x4(Matrix4x4 *A, Matrix4x4 *B) {
    Matrix4x4 mat = {0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            mat.m[i*4 + j] = 0;
            for (int k = 0; k < 4; k++) {
                mat.m[i*4 + j] += A->m[i*4 + k] * B->m[k*4 + j];
            }
        }
    }

	return mat;
}

static inline float degToRad(int angleInDegrees) {
    return ((angleInDegrees) * M_PI / 180.0);
}