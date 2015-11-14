#include "GCAnimatedTexture.h"
#include "com/mojang/minecraftpe/client/renderer/textures/TextureGroup.h"
#include "com/mojang/minecraftpe/client/renderer/textures/TextureData.h"

GCAnimatedTexture::GCAnimatedTexture(TextureGroup& textures, const TextureUVCoordinateSet& atlasTemplate, const std::string& png, bool isHD):
	TickingTexture(atlasTemplate, 1) {
	// Attempt to use 32x32 textures.
	this->isHD = isHD;

	TextureData& data = textures->getTextureData(png);
	pixelCount = data.width * data.height * 4;
	image = new char[pixelCount];

	memcpy(image, data.pixels, pixelCount);
	frameCount = data.height / (isHD)? 32 : 16;
	currentFrame = 0;
}

void GCAnimatedTexture::tick() {
	memcpy(frameBuffer, image + (currentFrame * getSizeOfFrame()), getSizeOfFrame());
	++currentFrame;

	if(currentFrame >= frameCount)
		currentFrame = 0;
}

char GCAnimatedTexture::getSizeOfFrame() {
	return 1024 * (((char) isHD) + 1);
}
