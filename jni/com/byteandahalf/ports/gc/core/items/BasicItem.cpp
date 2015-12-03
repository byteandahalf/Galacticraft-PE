#include "BasicItem.h"
#include "com/mojang/minecraftpe/world/item/ItemInstance.h"

std::string BasicItem::names[NUMBER_OF_ITEMS] = { "solar_module0", "solar_module1", "rawSilicon", "ingotCopper", "ingotTin", "ingotAluminum", "compressedCopper", "compressedTin", "compressedAluminum", "compressedSteel", "compressedBronze", "compressedIron", "waferSolar", "waferBasic", "waferAdvanced", "frequencyModule", "ambientThermalController" };

BasicItem::BasicItem(int itemId):
	GalacticraftItem("basicItem", itemId) {
	creativeCategory = 3;
	setMaxDamage(0);
	setStackedByData(false);
	
	initIcons();
}

void BasicItem::initIcons() {
	int i = 0;
	
	for(const std::string name : names) {
		icons[i++] = getTextureUVCoordinateSet("basicItem." + name, 0);
	}
}

void BasicItem::addCreativeItems() {
	for(int i = 0; i < NUMBER_OF_ITEMS; i++)
		addCreativeItem(this, i);
}

int BasicItem::getLevelDataForAuxValue(int aux) const {
	return aux;
}

const std::string BasicItem::buildDescriptionName(const ItemInstance& stack) const {
	return GalacticraftItem::GC_ITEM_PREFIX + "basicItem." + names[stack.aux] + ".name";
}

const TextureUVCoordinateSet& BasicItem::getIcon(int aux, int, bool) const {
	return icons[aux];
}

