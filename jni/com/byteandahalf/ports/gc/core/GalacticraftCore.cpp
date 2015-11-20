#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <substrate.h>
#include <string>
#include <memory>
#include "tinyhook.h"

#include "com/mojang/minecraftpe/world/level/block/Block.h"
#include "com/mojang/minecraftpe/world/level/block/LiquidBlock.h"
#include "com/mojang/minecraftpe/world/material/Material.h"
#include "com/mojang/minecraftpe/world/entity/Entity.h"
#include "com/mojang/minecraftpe/world/item/Item.h"
#include "com/mojang/minecraftpe/world/level/biome/BiomeDecorator.h"
#include "com/mojang/minecraftpe/client/MinecraftClient.h"
#include "com/mojang/minecraftpe/client/renderer/entity/EntityRenderDispatcher.h"

#include "blocks/GCBlocks.h"
#include "blocks/BlockFluidDynamicGC.h"
#include "fluid/GCFluidHandler.h"
#include "items/GCItems.h"
#include "creative/GCCreativeManager.h"
#include "world/wgen/GCFeatures.h"
#include "texture/GCAnimatedTexture.h"
#include "hook/GCHookBucketItem.h"
#include "entity/GCEntityFactory.h"
#include "render/entity/GCEntityRenderDispatcher.h"


void (*_Block$initBlocks)();
void Block$initBlocks() {
	_Block$initBlocks();

	GCBlocks::initBlocks();
}

void (*_Item$initItems)();
void Item$initItems() {
	_Item$initItems();

	GCItems::initItems();
	GCHook::BucketItem::setupHooks();
}

void (*_Item$initCreativeItems)();
void Item$initCreativeItems() {
	_Item$initCreativeItems();

	GCCreativeManager::registerCreativeItems();
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

int (*_LiquidBlock$getTickDelay)(LiquidBlock*, BlockSource&);
int LiquidBlock$getTickDelay(LiquidBlock* self, BlockSource& region) {
	return 0xA;
	if(!self->material.isType(MaterialType::WATER) && !self->material.isType(MaterialType::LAVA))
		return BlockFluidDynamicGC::getTickDelay(self, region);

	return _LiquidBlock$getTickDelay(self, region);
}

Vec3 (*_LiquidBlock$_getFlow)(LiquidBlock*, BlockSource&, const BlockPos&);
Vec3 LiquidBlock$_getFlow(LiquidBlock* self, BlockSource& region, const BlockPos& pos) {
	if(!self->material.isType(MaterialType::WATER) && !self->material.isType(MaterialType::LAVA))
		return BlockFluidDynamicGC::_getFlow(self, region, pos);

	return _LiquidBlock$_getFlow(self, region, pos);
}

void (*_Material$_setupSurfaceMaterials)();
void Material$_setupSurfaceMaterials() {
	_Material$_setupSurfaceMaterials();
	
	GCBlocks::initMaterials();
}

std::unique_ptr<Entity> (*_EntityFactory$CreateEntity)(EntityType, BlockSource&);
std::unique_ptr<Entity> EntityFactory$CreateEntity(EntityType type, BlockSource& region) {
	std::unique_ptr<Entity> retval = _EntityFactory$CreateEntity(type, region);
	if(!retval)
		return GCEntityFactory::CreateEntity(type, region);

	return retval;
}

EntityRenderer* EntityRenderDispatcher$getRenderer(EntityRenderDispatcher* self, int rendererId) {
	EntityRenderer* retval = GCEntityRenderDispatcher::getRenderer(self, rendererId);
	if(!retval)
		return self->renderers[rendererId].get();

	return retval;
}

void (*_Entity$updateWaterState)(Entity*);
void Entity$updateWaterState(Entity* self) {
	_Entity$updateWaterState(self);

	if(!self->wasInWater)
		GCFluidHandler::handleEntitySwim(self);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &BiomeDecorator::decorateOres, (void*) &BiomeDecorator$decorateOres, (void**) &_BiomeDecorator$decorateOres);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &MinecraftClient::init, (void*) &MinecraftClient$init, (void**) &_MinecraftClient$init);
	tiny_hook((uint32_t*)(void*) &LiquidBlock::getTickDelay, (uint32_t) &LiquidBlock$getTickDelay/*, (void**) &_LiquidBlock$getTickDelay*/);
	MSHookFunction((void*) &Material::_setupSurfaceMaterials, (void*) &Material$_setupSurfaceMaterials, (void**) &_Material$_setupSurfaceMaterials);
	MSHookFunction((void*) &LiquidBlock::_getFlow, (void*) &LiquidBlock$_getFlow, (void**) &_LiquidBlock$_getFlow);
	MSHookFunction((void*) &Entity::updateWaterState, (void*) &Entity$updateWaterState, (void**) &_Entity$updateWaterState);
	tiny_hook((uint32_t*)(void*) &EntityRenderDispatcher::getRenderer, (uint32_t) &EntityRenderDispatcher$getRenderer);

	return JNI_VERSION_1_2;
}
