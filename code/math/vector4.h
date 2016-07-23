#ifndef __VECTOR4_H__
#define __VECTOR4_H__

typedef struct Vector4 {
	float x, y, z, w;
} Vector4;

// default vectors
// ===============
//

// vector utility
// ==============
void		vec4_copy(Vector4 *dst, const Vector4 *src);

// vector arithmetic
// =================
float		vec4_norm(const Vector4 *v);
float		vec4_sqrnorm(const Vector4 *v);
void		vec4_normalize(Vector4 *v);
void		vec4_multf(Vector4 *v, const float f);
void		vec4_add(Vector4 *v, const Vector4 *u);
void		vec4_sub(Vector4 *v, const Vector4 *u);
float		vec4_dot(const Vector4 *v, const Vector4 *u);

#endif // __VECTOR4_H__