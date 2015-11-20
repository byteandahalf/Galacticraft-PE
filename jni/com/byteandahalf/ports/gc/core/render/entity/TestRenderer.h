#pragma once
#include "com/mojang/minecraftpe/client/renderer/entity/EntityRenderer.h"

class TestRenderer : public EntityRenderer {
public:
	TestRenderer(TextureGroup&);
	
	virtual void render(Entity&, const Vec3&, float, float);
};

