#pragma once
#include "../Entity.h"
class ItemInstance;

class Player : public Entity {
public:
	char filler2[2971];
	bool creativeMode;
	
	void drop(const ItemInstance*);
};
