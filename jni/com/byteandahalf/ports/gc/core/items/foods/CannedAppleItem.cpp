#include "CannedAppleItem.h"

CannedAppleItem::CannedAppleItem(int itemId):
	CannedFoodItem("apple", itemId) {
}

int CannedAppleItem::getHealAmount() {
	return 8;
}

float CannedAppleItem::getSaturationModifier() {
	return GCFoodItem::SATURATION_LOW;
}

