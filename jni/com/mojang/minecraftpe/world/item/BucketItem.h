#pragma once
#include "Item.h"
#include "../../client/renderer/texture/TextureUVCoordinateSet.h"

class BucketItem : public Item {
public:
	BucketItem(const std::string&, int);

	virtual ~BucketItem();
	virtual void setMaxStackSize(unsigned char);
	virtual bool isLiquidClipItem(int) const;
	virtual bool use(ItemInstance&, Player&);
	virtual bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
	virtual void useTimeDepleted(ItemInstance*, Level*, Player*);
	virtual const std::string& buildDescriptionName(const ItemInstance&) const;
	virtual bool isEmissive(int) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;

	TextureUVCoordinateSet _emptyIcon;
	TextureUVCoordinateSet _lavaIcon;
	TextureUVCoordinateSet _milkIcon;
	TextureUVCoordinateSet _waterIcon;
};
