#pragma once
#include <vector>
#include "../../../AppPlatformListener.h"
#include "../../renderer/texture/MaterialPtr.h"
class Entity;
class Mob;
class ModelPart;
namespace mce {
	class TexturePtr;
};

class Model : public AppPlatformListener {
public:
	float attackTime; // 8
	bool isChild; // 12
	bool isRiding; // 13
	mce::MaterialPtr* _material; // 16
	mce::TexturePtr* _texture; // 20
	char materials[108]; // 24
	std::vector<ModelPart*> _parts; // 132

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
