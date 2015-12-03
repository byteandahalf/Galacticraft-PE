#pragma once
#include "../GalacticraftItem.h"

class GCFoodItem : public GalacticraftItem {
protected:
	static float SATURATION_POOR;
	static float SATURATION_LOW;
	static float SATURATION_MID;
	static float SATURATION_HIGH;
	static float SATURATION_MAX;
	static float SATURATION_SUPERNATURAL;

public:
	GCFoodItem(const std::string&, int);
	
	virtual int getHealAmount() = 0;
	virtual float getSaturationModifier() = 0;
	virtual bool canFeedToDog();
	virtual const std::string getFinishEatingSound();
	virtual void registerEatEffects();
};

