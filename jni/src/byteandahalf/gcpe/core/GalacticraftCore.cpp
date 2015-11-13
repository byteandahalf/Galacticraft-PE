#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <substrate.h>
#include <string>

#include "com/mojang/minecraftpe/world/level/block/Block.h"

#include "blocks/GCBlocks.h"


void (*_Block$initBlocks)();
void Block$initBlocks() {
	_Block$initBlocks();

	GCBlocks::initBlocks();
}


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	
	return JNI_VERSION_1_2;
}
