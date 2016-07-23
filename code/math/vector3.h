#ifndef __VECTOR3_H__
#define __VECTOR3_H__

typedef struct Vector3 {
	float x, y, z;
} Vector3;

// default vectors
// ===============
extern		const Vector3 *vec3_zero;
extern		const Vector3 *vec3_up;
extern		const Vector3 *vec3_right;
extern		const Vector3 *vec3_forward;

// vector utility
// ==============
void		vec3_copy(Vector3 *dst, const Vector3 *src);

// vector arithmetic
// =================
float		vec3_norm(const Vector3 *v);
float		vec3_sqrnorm(const Vector3 *v);
void		vec3_normalize(Vector3 *v);
void		vec3_multf(Vector3 *v, const float f);
void		vec3_add(Vector3 *v, const Vector3 *u);
void		vec3_sub(Vector3 *v, const Vector3 *u);
float		vec3_dot(const Vector3 *v, const Vector3 *u);
void		vec3_cross(Vector3 *dst, const Vector3 *v, const Vector3 *u);

#endif // __VECTOR3_H__