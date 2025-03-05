#include "transform.h"

Vec4 _3DR_Trans_transformVertex(Vec4 vertex, Matrix4x4 *transformMatrix) {
    Vec4 result;
    result.x = vertex.x * transformMatrix->m[ 0] + vertex.y * transformMatrix->m[ 1] + vertex.z * transformMatrix->m[ 2] + vertex.w * transformMatrix->m[ 3];
    result.y = vertex.x * transformMatrix->m[ 4] + vertex.y * transformMatrix->m[ 5] + vertex.z * transformMatrix->m[ 6] + vertex.w * transformMatrix->m[ 7];
    result.z = vertex.x * transformMatrix->m[ 8] + vertex.y * transformMatrix->m[ 9] + vertex.z * transformMatrix->m[10] + vertex.w * transformMatrix->m[11];		
    result.w = vertex.x * transformMatrix->m[12] + vertex.y * transformMatrix->m[13] + vertex.z * transformMatrix->m[14] + vertex.w * transformMatrix->m[15];
    return result;
}

void _3DR_Trans_transformVertices(Vec4 *vertices, int vertexCount, Vec4 *transformedVertices, Matrix4x4 *transformMatrix) {
    for (int i = 0; i < vertexCount; i++) {
        transformedVertices[i].x = vertices[i].x * transformMatrix->m[0] + vertices[i].y * transformMatrix->m[1] + vertices[i].z * transformMatrix->m[2] + vertices[i].w * transformMatrix->m[3];
		transformedVertices[i].y = vertices[i].x * transformMatrix->m[4] + vertices[i].y * transformMatrix->m[5] + vertices[i].z * transformMatrix->m[6] + vertices[i].w * transformMatrix->m[7];
		transformedVertices[i].z = vertices[i].x * transformMatrix->m[8] + vertices[i].y * transformMatrix->m[9] + vertices[i].z * transformMatrix->m[10] + vertices[i].w * transformMatrix->m[11];		
		transformedVertices[i].w = vertices[i].x * transformMatrix->m[12] + vertices[i].y * transformMatrix->m[13] + vertices[i].z * transformMatrix->m[14] + vertices[i].w * transformMatrix->m[15];
    }
}

void _3DR_Trans_normalizeVertices(Vec4 *vertices, int vertexCount, Vec4 *normalizedVertices) {
    for (int i = 0; i < vertexCount; i++) {
        normalizedVertices[i].x = vertices[i].x / vertices[i].w;
        normalizedVertices[i].y = vertices[i].y / vertices[i].w;
        normalizedVertices[i].z = vertices[i].z / vertices[i].w;
		normalizedVertices[i].w = 1;
    }
}