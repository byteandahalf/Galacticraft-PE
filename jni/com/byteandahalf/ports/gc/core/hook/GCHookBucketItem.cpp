#include "GCHook.h"
#include "../items/GCItems.h"
#include "com/mojang/minecraftpe/world/item/BucketItem.h"
#include "com/mojang/minecraftpe/world/item/ItemInstance.h"

void GCHook::BucketItem::initHooks() {
	void** vtable = *((void***) Item::mBucket);
	initReals(vtable);

	vtable[45] = (void*) &GCHook::BucketItem::getIcon;
	vtable[38] = (void*) &GCHook::BucketItem::buildDescriptionName;

	pushCreativeBuckets();
}

void GCHook::BucketItem::initReals(void** vtable) {
	GCHook::BucketItem::_buildDescriptionName = (const std::string& (*)(BucketItem*, const ItemInstance&)) vtable[38];
}

void GCHook::BucketItem::pushCreativeBuckets() {
	GCItems::pushCreativeItem(ItemInstance(Item::mBucket, 201));
}

const TextureUVCoordinateSet& GCHook::BucketItem::getIcon(BucketItem* bucket, int data, int, bool) {
	switch(data) {
	case 1:
		return bucket->_milkIcon;
	case 8:
		return bucket->_waterIcon;
	case 10:
		return bucket->_lavaIcon;
	case 201:
		return Item::getTextureUVCoordinateSet("oilBucket", 0);
	default:
		return bucket->_emptyIcon;
	}
}

const std::string& (*GCHook::BucketItem::_buildDescriptionName)(BucketItem*, const ItemInstance&);
const std::string& GCHook::BucketItem::buildDescriptionName(BucketItem* bucket, const ItemInstance& item) {
	if(item->aux == 201)
		return "item.oilBucket.name";

	return GCHook::BucketItem::_buildDescriptionName(bucket, item);
}
