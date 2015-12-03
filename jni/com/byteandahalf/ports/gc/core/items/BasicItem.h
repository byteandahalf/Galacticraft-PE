#pragma once
#include "GalacticraftItem.h"
#include "com/mojang/minecraftpe/client/renderer/texture/TextureUVCoordinateSet.h"

#define NUMBER_OF_ITEMS 17

class BasicItem : public GalacticraftItem {
	static std::string names[NUMBER_OF_ITEMS];
	TextureUVCoordinateSet icons[NUMBER_OF_ITEMS];
	
	void initIcons();

public:
	BasicItem(int);
	
	virtual int getLevelDataForAuxValue(int) const;
	virtual const std::string buildDescriptionName(const ItemInstance&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	
	void addCreativeItems();
};

