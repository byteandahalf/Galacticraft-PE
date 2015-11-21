#pragma once
#include "com/mojang/minecraftpe/client/renderer/entity/EntityRenderer.h"
#include "models/Tier1RocketModel.h"
class Tier1RocketEntity;

class Tier1RocketRenderer : public EntityRenderer {
	Tier1RocketModel rocketModel;

	void renderTier1Rocket(Tier1RocketEntity&, const Vec3&, float, float);

public:
	Tier1RocketRenderer(TextureGroup&);
	
	virtual void render(Entity&, const Vec3&, float, float);
};

