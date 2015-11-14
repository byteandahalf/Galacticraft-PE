#pragma once
#include "TextureUVCoordinateSet.h"
class TextureGroup;

class TickingTexture {
protected:
	TextureUVCoordinateSet atlasTemplate; // 4
	int replicateValue; // 36
	char* frameBuffer; // 40
	int totalPixels; // 44
	char filler[16]; // 48

public:
	TickingTexture(const TextureUVCoordinateSet&, int);

	virtual ~TickingTexture();
	virtual void tick() = 0;
	virtual void bindTexture(TextureGroup&);
};
