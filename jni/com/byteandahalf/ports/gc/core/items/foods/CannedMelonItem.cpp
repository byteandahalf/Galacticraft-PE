#include "CannedMelonItem.h"

CannedMelonItem::CannedMelonItem(int itemId):
	CannedFoodItem("melon", itemId) {
}

int CannedMelonItem::getHealAmount() {
	return 4;
}

float CannedMelonItem::getSaturationModifier() {
	return GCFoodItem::SATURATION_LOW;
}

