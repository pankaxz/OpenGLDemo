#pragma once

#include <math.h>

const float pi = 3.141593;

struct mat4f {
	// Column-major order
	float
		x11, x21, x31, x41,
		x12, x22, x32, x42,
		x13, x23, x33, x43,
		x14, x24, x34, x44;
};

// Return the given matrix in a format understood by OpenGL.
float* mat4f_gl(struct mat4f* m) {
	// Since it's already in colum-major order, we just return the address of the
	// first element.
	return &m->x11;
}

struct mat4f mat4f_identity = {
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1,
};

struct mat4f mat4f_multiply(struct mat4f a, struct mat4f b) {
	return (struct mat4f) {
		a.x11 * b.x11 + a.x12 * b.x21 + a.x13 * b.x31 + a.x14 * b.x41,
		a.x21 * b.x11 + a.x22 * b.x21 + a.x23 * b.x31 + a.x24 * b.x41,
		a.x31 * b.x11 + a.x32 * b.x21 + a.x33 * b.x31 + a.x34 * b.x41,
		a.x41 * b.x11 + a.x42 * b.x21 + a.x43 * b.x31 + a.x44 * b.x41,

		a.x11 * b.x12 + a.x12 * b.x22 + a.x13 * b.x32 + a.x14 * b.x42,
		a.x21 * b.x12 + a.x22 * b.x22 + a.x23 * b.x32 + a.x24 * b.x42,
		a.x31 * b.x12 + a.x32 * b.x22 + a.x33 * b.x32 + a.x34 * b.x42,
		a.x41 * b.x12 + a.x42 * b.x22 + a.x43 * b.x32 + a.x44 * b.x42,

		a.x11 * b.x13 + a.x12 * b.x23 + a.x13 * b.x33 + a.x14 * b.x43,
		a.x21 * b.x13 + a.x22 * b.x23 + a.x23 * b.x33 + a.x24 * b.x43,
		a.x31 * b.x13 + a.x32 * b.x23 + a.x33 * b.x33 + a.x34 * b.x43,
		a.x41 * b.x13 + a.x42 * b.x23 + a.x43 * b.x33 + a.x44 * b.x43,

		a.x11 * b.x14 + a.x12 * b.x24 + a.x13 * b.x34 + a.x14 * b.x44,
		a.x21 * b.x14 + a.x22 * b.x24 + a.x23 * b.x34 + a.x24 * b.x44,
		a.x31 * b.x14 + a.x32 * b.x24 + a.x33 * b.x34 + a.x34 * b.x44,
		a.x41 * b.x14 + a.x42 * b.x24 + a.x43 * b.x34 + a.x44 * b.x44,
	};
}

struct mat4f mat4f_scale(float x, float y, float z) {
	return (struct mat4f){
		x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, 0,
		0, 0, 0, 1,
	};
}

struct mat4f mat4f_translation(float x, float y, float z) {
	return (struct mat4f) {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		x, y, z, 1,
	};
}

struct mat4f mat4f_rotate_z(float theta) {
	return (struct mat4f) {
		 cos(theta), sin(theta), 0, 0,
		-sin(theta), cos(theta), 0, 0,
		          0,          0, 1, 0,
		          0,          0, 0, 1,
	};
}

struct mat4f mat4f_rotate_y(float theta) {
	return (struct mat4f) {
		cos(theta), 0, -sin(theta), 0,
		         0, 1,           0, 0,
		sin(theta), 0,  cos(theta), 0,
		         0, 0,           0, 1,
	};
}

inline struct mat4f mat4f_rotate_x(float theta) {
	return (struct mat4f) {
		1, 0, 0, 0,
		0, cos(theta), sin(theta), 0,
		0, -sin(theta), cos(theta), 0,
		0, 0, 0, 1,
	};
}

struct mat4f mat4f_perspective() {
	// Based on http://www.songho.ca/opengl/gl_projectionmatrix.html, which I don't
	// really understand. I just copied the final result.

	const float
		r = 0.5,  // Half of the viewport width (at the near plane)
		t = 0.5,  // Half of the viewport height (at the near plane)
		n = 1,  // Distance to near clipping plane
		f = 5;  // Distance to far clipping plane

	// Note that while n and f are given as positive integers above,
	// the camera is looking in the negative direction. So we will see
	// stuff between z = -n and z = -f.

	return (struct mat4f) {
		n / r, 0, 0, 0,
		0, n / t, 0, 0,
		0, 0, (-f - n) / (f - n), -1,
		0, 0, (2 * f * n) / (n - f), 0,
	};
}