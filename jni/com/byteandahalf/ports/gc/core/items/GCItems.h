#pragma once
#include <vector>
class Item;
class ItemInstance;

class GCItems {
public:
	static Item* basicItem;

	static std::vector<ItemInstance&> creativeItems;

	static void registerItems();
	static void pushCreativeItem(ItemInstance&);
};
