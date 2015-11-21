#pragma once
#include <vector>
struct Vec3;
class Model;
class Cube;
namespace mce { class MaterialPtr; };
#include "../../renderer/renderer/Mesh.h"
#include "../../../world/phys/Vec3.h"

class ModelPart {
public:
	Vec3 rotationPoints; // 0
	Vec3 pos; // 12
	bool mirror; // 24
	bool visible; // 25
	std::vector<Cube*> _cubeList; // 28
	std::vector<ModelPart*> _children; // 40
	float textureWidth, textureHeight; // 52, 56
	mce::MaterialPtr* material; // 60
	int textureX, textureY; // 64, 68
	bool neverRender; // 72
	mce::Mesh mesh; // 76
	Vec3 rotationAngles; // 156

	ModelPart(int, int, int, int);

	void addBox(const Vec3&, const Vec3&, float);
	void setPos(const Vec3&);
	ModelPart& texOffs(int, int);
	ModelPart& setTexSize(int, int);
	void setNeverRender(bool);
	void reset();
	void compile(float);
	void addChild(ModelPart*);
	void render(const Model&, float);
};
