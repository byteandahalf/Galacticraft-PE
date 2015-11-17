#pragma once
class CompoundTag;
class Item;
class Block;

class ItemInstance {
public:
	short count, aux;
	CompoundTag* userData;
	Item* item;
	Block* block;
	bool valid;

	ItemInstance();
	ItemInstance(int, int, int);
	ItemInstance(const Item*, int);
	ItemInstance(const Item*, int, int);
	ItemInstance(const Block*, int);
	ItemInstance(const Block*, int, int);
	ItemInstance(const ItemInstance&);
};
