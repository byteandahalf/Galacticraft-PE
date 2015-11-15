#include "GCItems.h"
#include "com/mojang/minecraftpe/world/item/Item.h"

Item* GCItems::basicItem;

std::vector<ItemInstance&> GCItems::creativeItems;

void GCItems::registerItems() {
}

void GCItems::pushCreativeItem(ItemInstance& stack) {
	creativeItems.push_back(stack);
}
