#include "GCAnimatedTextures.h"
#include "GCAnimatedTexture.h"
#include "com/mojang/minecraftpe/client/renderer/texture/TextureGroup.h"
#include "com/mojang/minecraftpe/world/level/block/Block.h"

void GCAnimatedTextures::initAnimatedTextures(TextureGroup& textures) {
	textures->addTickingTexture(std::unique_ptr<TickingTexture>(new GCAnimatedTexture(textures, Block::mBlocks[1]->texture, "oilStill_animation.png", false)));
}
