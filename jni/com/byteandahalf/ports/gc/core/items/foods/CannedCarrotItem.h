#pragma once
#include "CannedFoodItem.h"

class CannedCarrotItem : public CannedFoodItem {
public:
	CannedCarrotItem(int);
	
	virtual int getHealAmount();
	virtual float getSaturationModifier();
};

