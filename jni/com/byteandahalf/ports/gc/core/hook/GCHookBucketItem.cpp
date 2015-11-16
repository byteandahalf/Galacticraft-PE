#include "GCHookBucketItem.h"
#include "com/mojang/minecraftpe/world/item/BucketItem.h"
#include "com/mojang/minecraftpe/world/item/ItemInstance.h"
#include "../GCUtil.h"

#define ADDRESS_BUILDDESCRIPTIONNAME 37
#define ADDRESS_GETICON 45

TextureUVCoordinateSet GCHook::BucketItem::OilBucketIcon;

void GCHook::BucketItem::setupHooks() {
	void** vtable = GCUtil::getInstanceVtable((void*) Item::mBucket);
	setupReals(vtable);

	vtable[ADDRESS_GETICON] = (void*) &GCHook::BucketItem::getIcon;
	vtable[ADDRESS_BUILDDESCRIPTIONNAME] = (void*) &GCHook::BucketItem::buildDescriptionName;
	
	postSetup();
}

void GCHook::BucketItem::setupReals(void** vtable) {
	GCHook::BucketItem::_getIcon = (const TextureUVCoordinateSet& (*)(::BucketItem*, int, int, bool)) vtable[ADDRESS_GETICON];
	GCHook::BucketItem::_buildDescriptionName = (std::string (*)(::BucketItem*, const ItemInstance&)) vtable[ADDRESS_BUILDDESCRIPTIONNAME];
}

void GCHook::BucketItem::postSetup() {
	OilBucketIcon = Item::getTextureUVCoordinateSet("oilBucket", 0);
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
