#include "vector.h"

Vec3 Vec3_crossProduct(Vec3 v1, Vec3 v2) {
    Vec3 result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return Vec3_normalize(result);
}
float Vec3_dotProduct(Vec3 v1, Vec3 v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
Vec3 Vec3_normalize(Vec3 v) {
    float length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    if (length != 0) {
        v.x /= length;
        v.y /= length;
        v.z /= length;
    }
    return v;
}