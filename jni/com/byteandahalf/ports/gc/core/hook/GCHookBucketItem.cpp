#include "GCHookBucketItem.h"
#include "com/mojang/minecraftpe/world/item/BucketItem.h"
#include "com/mojang/minecraftpe/world/entity/player/Player.h"
#include "com/mojang/minecraftpe/world/level/BlockSource.h"
#include "com/mojang/minecraftpe/world/item/ItemInstance.h"
#include "../GCUtil.h"

#define ADDRESS_USEON 30
#define ADDRESS_BUILDDESCRIPTIONNAME 37
#define ADDRESS_GETICON 45

TextureUVCoordinateSet GCHook::BucketItem::OilBucketIcon;

void GCHook::BucketItem::setupHooks() {
	void** vtable = GCUtil::getInstanceVtable((void*) Item::mBucket);
	setupReals(vtable);

	vtable[ADDRESS_USEON] = (void*) &GCHook::BucketItem::useOn;
	vtable[ADDRESS_GETICON] = (void*) &GCHook::BucketItem::getIcon;
	vtable[ADDRESS_BUILDDESCRIPTIONNAME] = (void*) &GCHook::BucketItem::buildDescriptionName;
	
	postSetup();
}

void GCHook::BucketItem::setupReals(void** vtable) {
	GCHook::BucketItem::_useOn = (bool (*)(::BucketItem*, ItemInstance*, Player*, int, int, int, signed char, float, float, float)) vtable[ADDRESS_USEON];
	GCHook::BucketItem::_getIcon = (const TextureUVCoordinateSet& (*)(::BucketItem*, int, int, bool)) vtable[ADDRESS_GETICON];
	GCHook::BucketItem::_buildDescriptionName = (std::string (*)(::BucketItem*, const ItemInstance&)) vtable[ADDRESS_BUILDDESCRIPTIONNAME];
}

void GCHook::BucketItem::postSetup() {
	OilBucketIcon = Item::getTextureUVCoordinateSet("oilBucket", 0);
}

bool (*GCHook::BucketItem::_useOn)(::BucketItem*, ItemInstance*, Player*, int, int, int, signed char, float, float, float);
bool GCHook::BucketItem::useOn(::BucketItem* bucket, ItemInstance* stack, Player* player, int x, int y, int z, signed char side, float fX, float fY, float fZ) {
	if(player->region.getBlock({x, y, z})->blockId == 202) {
		player->region.removeBlock({x, y, z});
		if(!player->creativeMode)
			*stack = ItemInstance(325, 1, 201);
		return true;
	}

	return GCHook::BucketItem::_useOn(bucket, stack, player, x, y, z, side, fX, fY, fZ);
}

const TextureUVCoordinateSet& (*GCHook::BucketItem::_getIcon)(::BucketItem*, int, int, bool);
const TextureUVCoordinateSet& GCHook::BucketItem::getIcon(::BucketItem* bucket, int data, int par3, bool par4) {
	if(data == 201)
		return OilBucketIcon;

	return GCHook::BucketItem::_getIcon(bucket, data, par3, par4);
}

std::string (*GCHook::BucketItem::_buildDescriptionName)(::BucketItem*, const ItemInstance&);
std::string GCHook::BucketItem::buildDescriptionName(::BucketItem* bucket, const ItemInstance& item) {
	if(item.aux == 201)
		return "Oil Bucket"; // TODO: Localize

	return GCHook::BucketItem::_buildDescriptionName(bucket, item);
}
