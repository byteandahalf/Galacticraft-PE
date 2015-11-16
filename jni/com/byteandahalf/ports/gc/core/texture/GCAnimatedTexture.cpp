#include "GCAnimatedTexture.h"
#include "com/mojang/minecraftpe/client/renderer/texture/TextureGroup.h"
#include "com/mojang/minecraftpe/client/renderer/texture/TextureData.h"
#include "com/mojang/minecraftpe/client/renderer/texture/TextureAtlas.h"
#include "com/mojang/minecraftpe/client/renderer/texture/TextureAtlasTextureItem.h"
#include "com/mojang/minecraftpe/world/level/block/Block.h"

GCAnimatedTexture::GCAnimatedTexture(TextureGroup& textures, const std::string& atlasTemplate, const std::string& png, int ticks):
	TickingTexture(Block::mTerrainTextureAtlas->getTextureItem(atlasTemplate)[0], 1) {

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

void GCAnimatedTexture::initAnimatedTextures(TextureGroup& textures) {
	textures.addTickingTexture(std::unique_ptr<TickingTexture>(new GCAnimatedTexture(textures, "oilStill", "animations/oilStill_animation.png", 1)));
	textures.addTickingTexture(std::unique_ptr<TickingTexture>(new GCAnimatedTexture(textures, "oilFlowing", "animations/oilFlowing_animation.png", 1)));
}

