#pragma once
#include "CannedFoodItem.h"

class CannedPotatoItem : public CannedFoodItem {
public:
	CannedPotatoItem(int);
	
	virtual int getHealAmount();
	virtual float getSaturationModifier();
};

