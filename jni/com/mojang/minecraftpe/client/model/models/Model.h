#pragma once
#include "../../../AppPlatformListener.h"
class Entity;
class Mob;
class ModelPart;
namespace mce { class MaterialPtr; };

class Model : public AppPlatformListener {
protected:
	float attackTime; // 8
	bool isChild; // 12
	bool isRiding; // 13
	int idk; // 16
	mce::MaterialPtr* _material; // 20
	char materials[108]; // 24
	std::vector<ModelPart*> _parts; // 132

public:
	Model();

	virtual ~Model();
	virtual void onAppSuspended();
	virtual void clear();
	virtual void render();
	virtual void render(Entity&, float, float, float, float, float, float);
	virtual void setupAnim(float, float, float, float, float, float);
	virtual void prepareMobModel(Mob&, float, float, float);

	void registerParts(ModelPart&);
};
