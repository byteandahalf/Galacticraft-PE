#include "GCCreativeManager.h"
#include "../blocks/GCBlocks.h"
#include "../items/GCItems.h"
#include "../items/BasicItem.h"
#include "com/mojang/minecraftpe/world/item/Item.h"

void GCCreativeManager::registerCreativeItems() {
	Item::addCreativeItem(Item::mBucket, 201);
	Item::addCreativeItem(GCBlocks::basicBlock, 0);
	((BasicItem*)GCItems::basicItem)->addCreativeItems();
	Item::addCreativeItem(GCItems::cannedCarrot, 0);
	Item::addCreativeItem(GCItems::cannedApple, 0);
	Item::addCreativeItem(GCItems::cannedMelon, 0);
	Item::addCreativeItem(GCItems::cannedPotato, 0);
}

