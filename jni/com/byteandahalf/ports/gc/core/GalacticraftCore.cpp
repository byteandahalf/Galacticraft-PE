#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <substrate.h>
#include <string>
#include <memory>

#include "com/mojang/minecraftpe/world/level/block/Block.h"
#include "com/mojang/minecraftpe/world/level/biome/BiomeDecorator.h"

#include "blocks/GCBlocks.h"
#include "world/wgen/GCFeatures.h"


void (*_Block$initBlocks)();
void Block$initBlocks() {
	_Block$initBlocks();

	GCBlocks::initBlocks();
}

BiomeDecorator* (*_BiomeDecorator$BiomeDecorator)(BiomeDecorator*);
BiomeDecorator* BiomeDecorator$BiomeDecorator(BiomeDecorator* self) {
	BiomeDecorator* retval = _BiomeDecorator$BiomeDecorator(self);
	GCFeatures::setDecorator(retval);
	GCFeatures::initFeatures();
	return retval;
}

void (*_BiomeDecorator$decorateOres)(BiomeDecorator*, BlockSource*, Random&, const BlockPos&);
void BiomeDecorator$decorateOres(BiomeDecorator* self, BlockSource* region, Random& random, const BlockPos& pos) {
	_BiomeDecorator$decorateOres(self, region, random, pos);
	
	GCFeatures::populateFeatures(region, random, pos);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	MSHookFunction((void*) &BiomeDecorator::decorateOres, (void*) &BiomeDecorator$decorateOres, (void**) &_BiomeDecorator$decorateOres);
	
	void* BiomeDecorator$$BiomeDecorator = (void*) dlsym(RTLD_DEFAULT, "_ZN14BiomeDecoratorC2Ev");
	MSHookFunction(BiomeDecorator$$BiomeDecorator, (void*) &BiomeDecorator$BiomeDecorator, (void**) &_BiomeDecorator$BiomeDecorator);

	return JNI_VERSION_1_2;
}
