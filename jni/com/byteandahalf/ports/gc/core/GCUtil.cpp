#include "GCUtil.h"
#include "com/mojang/minecraftpe/world/item/Item.h"

void** GCUtil::getInstanceVtable(void* instance) {
	return *((void***) instance);
}

int GCUtil::getNextAvailableItemID() {
	// Doesn't work because I need to add my Items before vanilla items are added
	// I will work on a plan B later
	for(int itemId = 256; itemId < 4096; itemId++) {
		if(!Item::mItems[itemId])
			return itemId;
	}
	
	return 5000;
}

