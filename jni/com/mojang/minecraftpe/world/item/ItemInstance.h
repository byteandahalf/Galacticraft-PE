#pragma once
class CompoundTag;
class Item;
class Block;

class ItemInstance {
public:
	short count, data;
	CompoundTag* userData;
	Item* item;
	Block* block;
	bool valid;

	ItemInstance();
	ItemInstance(int, int, int);
};