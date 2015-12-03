#include "GCFoodItem.h"

float GCFoodItem::SATURATION_POOR = 0.1F;
float GCFoodItem::SATURATION_LOW = 0.3F;
float GCFoodItem::SATURATION_MID = 0.6F;
float GCFoodItem::SATURATION_HIGH = 0.8F;
float GCFoodItem::SATURATION_MAX = 1.0F;
float GCFoodItem::SATURATION_SUPERNATURAL = 1.2F;

GCFoodItem::GCFoodItem(const std::string& name, int itemId):
	GalacticraftItem(name, itemId) {
	creativeCategory = 3;
	setUseAnimation(UseAnimation::EATING);
	setMaxUseDuration(32);
	_foodDetails = std::unique_ptr<FoodItemComponent>(new FoodItemComponent(*this));
}

bool GCFoodItem::canFeedToDog() {
	return false;
}

const std::string GCFoodItem::getFinishEatingSound() {
	return "random.burp";
}

void GCFoodItem::registerEatEffects() {
	
}

