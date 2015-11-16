#pragma once
#include <string>
#include "com/mojang/minecraftpe/client/renderer/texture/TickingTexture.h"

class GCAnimatedTexture : public TickingTexture {
	short getSizeOfFrame();
	
protected:
	int frameCount;
	int currentFrame;
	int pixelCount;
	char* image;
	bool isHD;
	int currentTick;
	int speed;

public:
	GCAnimatedTexture(TextureGroup&, const std::string&, const std::string&, int);

	virtual void tick();
	
	static void initAnimatedTextures(TextureGroup&);
};
