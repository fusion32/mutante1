
#ifndef __QUATERNION_H__
#define __QUATERNION_H__

#define M_PI		3.14159265358979323846
#define DEG2RAD		(float)(M_PI / 180.0f)
#define RAD2DEG		(float)(M_PI * 180.0f)

typedef struct Quaternion {
	float w, x, y, z;
} Quaternion;

typedef struct Vector3 Vector3;
typedef struct Matrix4 Matrix4;

// identity
// ========
extern		const Quaternion *quat_identity;

// quaternion utility
// ==================
void		quat_copy(Quaternion *dst, const Quaternion *src);
void		quat_tomatrix(Matrix4 *dst, const Quaternion *q);
void		quat_angleaxis(Quaternion *dst, const float angle, const Vector3 *axis);
void		quat_rotationbetween(Quaternion *dst, const Vector3 *v, const Vector3 *u);
void		quat_rotatev3(Vector3 *dst, const Quaternion *q, const Vector3 *v);

// quaternion arithmetic
// ===============
float		quat_norm(const Quaternion *q);
float		quat_sqrnorm(const Quaternion *q);
void		quat_normalize(Quaternion *q);
void		quat_conjugate(Quaternion *q);

void		quat_mult(Quaternion *dst, const Quaternion *a, const Quaternion *b);

#endif //__QUATERNION_H__