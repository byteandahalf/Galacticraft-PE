#include "GalacticraftItem.h"

std::string GalacticraftItem::GC_ITEM_PREFIX = "gcItem.";

GalacticraftItem::GalacticraftItem(const std::string& name, int itemId):
	Item(name, itemId - 0x100) {
}

const std::string GalacticraftItem::buildDescriptionName(const ItemInstance& stack) const {
	return GC_ITEM_PREFIX + this->name + ".name";
}

