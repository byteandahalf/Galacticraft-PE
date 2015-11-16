#include "GCCreativeManager.h"
#include "../blocks/GCBlocks.h"
#include "../items/GCItems.h"
#include "com/mojang/minecraftpe/world/item/Item.h"

void GCCreativeManager::registerCreativeItems() {
	Item::addCreativeItem(Item::mBucket, 201);
	Item::addCreativeItem(GCBlocks::basicBlock, 0);
}
