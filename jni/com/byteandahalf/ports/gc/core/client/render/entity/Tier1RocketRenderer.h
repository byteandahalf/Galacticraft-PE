#pragma once
#include "com/mojang/minecraftpe/client/renderer/entity/EntityRenderer.h"
class Tier1RocketEntity;
class Tier1RocketModel;

class Tier1RocketRenderer : public EntityRenderer {
	Tier1RocketModel& rocketModel;

	void renderTier1Rocket(Tier1RocketEntity&, const Vec3&, float, float);

public:
	Tier1RocketRenderer(TextureGroup&, Tier1RocketModel&);
	
	virtual void render(Entity&, const Vec3&, float, float);
};

