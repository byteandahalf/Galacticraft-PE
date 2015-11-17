#pragma once
class BlockPos;

struct Vec3 {
	float x, y, z;

	Vec3(float, float, float);
	Vec3(const BlockPos&);

	const Vec3& extend(float, float, float);
	const Vec3& set(float, float, float);
	const Vec3& normalize();
};
