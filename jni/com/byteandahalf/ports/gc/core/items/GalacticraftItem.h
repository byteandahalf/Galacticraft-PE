#pragma once
#include "com/mojang/minecraftpe/world/item/Item.h"

class GalacticraftItem : public Item {
protected:
	static std::string GC_ITEM_PREFIX;

public:
	GalacticraftItem(const std::string&, int);

	virtual const std::string buildDescriptionName(const ItemInstance&) const;
};

