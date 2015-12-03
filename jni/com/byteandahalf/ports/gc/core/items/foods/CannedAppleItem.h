#pragma once
#include "CannedFoodItem.h"

class CannedAppleItem : public CannedFoodItem {
public:
	CannedAppleItem(int);
	
	virtual int getHealAmount();
	virtual float getSaturationModifier();
};

