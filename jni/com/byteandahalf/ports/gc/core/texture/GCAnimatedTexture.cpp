#include "GCAnimatedTexture.h"
#include "com/mojang/minecraftpe/client/renderer/texture/TextureGroup.h"
#include "com/mojang/minecraftpe/client/renderer/texture/TextureData.h"

GCAnimatedTexture::GCAnimatedTexture(TextureGroup& textures, const TextureUVCoordinateSet& atlasTemplate, const std::string& png, int ticks):
	TickingTexture(atlasTemplate, 1) {

	TextureData& data = textures.getTextureData(png);
	isHD = data.width > 16;
	// Multiply by 4 for RGBA
	pixelCount = data.width * data.height * 4;
	image = new char[pixelCount];

	memcpy(image, data.pixels, pixelCount);
	frameCount = data.height / data.width;
	currentFrame = 0;
	currentTick = 0;
	speed = ticks;
}

void GCAnimatedTexture::tick() {
	if(currentTick < speed) {
		currentTick++;
		return;
	}
	
	currentTick = 0;
	
	memcpy(frameBuffer, image + (currentFrame * getSizeOfFrame()), getSizeOfFrame());
	++currentFrame;

	if(currentFrame >= frameCount)
		currentFrame = 0;
}

short GCAnimatedTexture::getSizeOfFrame() {
	return 1024 * (((char) isHD) + 1);
}

