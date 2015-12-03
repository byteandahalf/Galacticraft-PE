#pragma once
#include "GCFoodItem.h"

class CannedFoodItem : public GCFoodItem {
public:
	CannedFoodItem(const std::string&, int);
	
	virtual void useTimeDepleted(ItemInstance*, Level*, Player*);
};

