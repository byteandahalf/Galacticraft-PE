#pragma once
class CompoundTag;
class Item;
class Block;

class ItemInstance {
public:
	uint8_t count;
	short aux;
	CompoundTag* userData;
	bool valid;
	Item* item;
	Block* block;

	ItemInstance();
	ItemInstance(int, int, int);
	ItemInstance(const Item*, int);
	ItemInstance(const Item*, int, int);
	ItemInstance(const Block*, int);
	ItemInstance(const Block*, int, int);
	ItemInstance(const ItemInstance&);
	
	const ItemInstance& operator=(const ItemInstance&);
	
	bool isLiquidClipItem();
};
