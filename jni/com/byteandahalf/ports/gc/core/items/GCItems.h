#pragma once
#include <vector>
class Item;
#include "com/mojang/minecraftpe/world/item/ItemInstance.h"

class GCItems {
public:
	static Item* basicItem;

	static std::vector<ItemInstance> creativeItems;

	static void initItems();
	static void pushCreativeItem(ItemInstance);
};
