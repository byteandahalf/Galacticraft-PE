#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <substrate.h>
#include <string>
#include <memory>

#include "com/mojang/minecraftpe/world/level/block/Block.h"
#include "com/mojang/minecraftpe/world/item/Item.h"
#include "com/mojang/minecraftpe/world/level/biome/BiomeDecorator.h"
#include "com/mojang/minecraftpe/client/MinecraftClient.h"

#include "blocks/GCBlocks.h"
#include "items/GCItems.h"
#include "world/wgen/GCFeatures.h"
#include "texture/GCAnimatedTexture.h"
#include "hook/GCHookBucketItem.h"


void (*_Block$initBlocks)();
void Block$initBlocks() {
	_Block$initBlocks();

	GCBlocks::initBlocks();
}

void (*_Item$initItems)();
void Item$initItems() {
	_Item$initItems();

	GCItems::initItems();
	GCHook::BucketItem::setupClass();
}

void (*_Item$initCreativeItems)();
void Item$initCreativeItems() {
	_Item$initCreativeItems();

	for(ItemInstance& stack : GCItems::creativeItems) {
		Item::addCreativeItem(stack);
	}
}

void (*_BiomeDecorator$decorateOres)(BiomeDecorator*, BlockSource*, Random&, const BlockPos&);
void BiomeDecorator$decorateOres(BiomeDecorator* self, BlockSource* region, Random& random, const BlockPos& pos) {
	_BiomeDecorator$decorateOres(self, region, random, pos);
	
	// Disable for now, since it's crashing sometimes.
	//GCFeatures::populateFeatures(self, region, random, pos);
}

void (*_MinecraftClient$init)(MinecraftClient*);
void MinecraftClient$init(MinecraftClient* self) {
	_MinecraftClient$init(self);

	GCAnimatedTexture::initAnimatedTextures(self->textures);
}


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &BiomeDecorator::decorateOres, (void*) &BiomeDecorator$decorateOres, (void**) &_BiomeDecorator$decorateOres);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &MinecraftClient::init, (void*) &MinecraftClient$init, (void**) &_MinecraftClient$init);

	return JNI_VERSION_1_2;
}
