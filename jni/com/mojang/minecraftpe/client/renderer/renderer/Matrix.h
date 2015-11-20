#pragma once
class Vec3;

struct Matrix {
	void translate(const Vec3&);
	void scale(const Vec3&);
	void rotate(float, const Vec3&);
};
