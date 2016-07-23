#include "tostring.h"

#include "math/vector2.h"
#include "math/vector3.h"
#include "math/vector4.h"
#include "math/quaternion.h"
#include "math/matrix4.h"

#include <stdio.h>

int vec2_tostring(char *dst, size_t dstlen, Vector2 *v)
{
	return snprintf(dst, dstlen, VEC2_STR_FORMAT, VEC2_STR_ARGS(v));
}

int vec3_tostring(char *dst, size_t dstlen, Vector3 *v)
{
	return snprintf(dst, dstlen, VEC3_STR_FORMAT, VEC3_STR_ARGS(v));
}

int vec4_tostring(char *dst, size_t dstlen, Vector4 *v)
{
	return snprintf(dst, dstlen, VEC4_STR_FORMAT, VEC4_STR_ARGS(v));
}

int quat_tostring(char *dst, size_t dstlen, Quaternion *q)
{
	return snprintf(dst, dstlen, QUAT_STR_FORMAT, QUAT_STR_ARGS(q));
}

int mat4_tostring(char *dst, size_t dstlen, Matrix4 *a)
{
	return snprintf(dst, dstlen, MAT4_STR_FORMAT, MAT4_STR_ARGS(a));
}