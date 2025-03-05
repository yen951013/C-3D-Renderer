#ifndef _3DR_TRANSFORM_H_
#define _3DR_TRANSFORM_H_

#include <math.h>
#include "../utils/vector.h"
#include "../utils/matrix.h"

Vec4 _3DR_Trans_transformVertex(Vec4 vertex, Matrix4x4 *transformMatrix);
void _3DR_Trans_transformVertices(Vec4 *vertices, int vertexCount, Vec4 *transformedVertices, Matrix4x4 *transformMatrix);
void _3DR_Trans_normalizeVertices(Vec4 *vertices, int vertexCount, Vec4 *normalizedVertices);

#endif  // _3DR_TRANSFORM_H_