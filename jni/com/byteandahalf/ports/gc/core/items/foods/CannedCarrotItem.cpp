#include "CannedCarrotItem.h"

CannedCarrotItem::CannedCarrotItem(int itemId):
	CannedFoodItem("carrot", itemId) {
}

int CannedCarrotItem::getHealAmount() {
	return 8;
}

float CannedCarrotItem::getSaturationModifier() {
	return GCFoodItem::SATURATION_MID;
}

