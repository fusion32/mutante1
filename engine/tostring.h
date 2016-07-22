#ifndef __TOSTRING_H__
#define __TOSTRING_H__

#if _MSC_VER < 1900
	//#define snprintf(dst, size, format, ...) sprintf_s((dst), (size), (format), __VA_ARGS__)
	#define snprintf sprintf_s
#endif

#define VEC2_STR_FORMAT		"vec2(%.2f, %.2f)"
#define VEC3_STR_FORMAT		"vec3(%.2f, %.2f, %.2f)"
#define VEC4_STR_FORMAT		"vec4(%.2f, %.2f, %.2f, %.2f)"
#define QUAT_STR_FORMAT		"quat(%.2f, %.2f, %.2f, %.2f)"

#define MAT4_STR_FORMAT		"mat4\n"						\
							"\t%.2f\t%.2f\t%.2f\t%.2f\n"	\
							"\t%.2f\t%.2f\t%.2f\t%.2f\n"	\
							"\t%.2f\t%.2f\t%.2f\t%.2f\n"	\
							"\t%.2f\t%.2f\t%.2f\t%.2f\n"

#define VEC2_STR_ARGS(v)	(v)->x, (v)->y
#define VEC3_STR_ARGS(v)	(v)->x, (v)->y, (v)->z
#define VEC4_STR_ARGS(v)	(v)->x, (v)->y, (v)->z, (v)->w
#define QUAT_STR_ARGS(q)	(q)->w, (q)->x, (q)->y, (q)->z

#define MAT4_STR_ARGS(a)	(a)->m11, (a)->m12, (a)->m13, (a)->m14,	\
							(a)->m21, (a)->m22, (a)->m23, (a)->m24,	\
							(a)->m31, (a)->m32, (a)->m33, (a)->m34,	\
							(a)->m41, (a)->m42, (a)->m43, (a)->m44

//
typedef struct Vector2 Vector2;
typedef struct Vector3 Vector3;
typedef struct Vector4 Vector4;
typedef struct Quaternion Quaternion;
typedef struct Matrix4 Matrix4;

int		vec2_tostring(char *dst, size_t dstlen, Vector2 *v);
int		vec3_tostring(char *dst, size_t dstlen, Vector3 *v);
int		vec4_tostring(char *dst, size_t dstlen, Vector4 *v);
int		quat_tostring(char *dst, size_t dstlen, Quaternion *q);
int		mat4_tostring(char *dst, size_t dstlen, Matrix4 *a);

#endif //__TOSTRING_H__