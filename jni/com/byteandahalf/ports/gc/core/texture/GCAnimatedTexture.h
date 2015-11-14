#pragma once
#include <string>
#include "com/mojang/minecraftpe/client/renderer/texture/TickingTexture.h"

class GCAnimatedTexture : public TickingTexture {
protected:
	int frameCount;
	int currentFrame;
	int pixelCount;
	char* image;
	bool isHD;

public:
	GCAnimatedTexture(TextureGroup&, const TextureUVCoordinateSet&, const std::string&, bool);

	virtual void tick();
	
	char getSizeOfFrame();
};
