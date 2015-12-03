#pragma once
#include "CannedFoodItem.h"

class CannedMelonItem : public CannedFoodItem {
public:
	CannedMelonItem(int);
	
	virtual int getHealAmount();
	virtual float getSaturationModifier();
};

