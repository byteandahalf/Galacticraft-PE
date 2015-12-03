#include "CannedPotatoItem.h"

CannedPotatoItem::CannedPotatoItem(int itemId):
	CannedFoodItem("potato", itemId) {
}

int CannedPotatoItem::getHealAmount() {
	return 2;
}

float CannedPotatoItem::getSaturationModifier() {
	return GCFoodItem::SATURATION_LOW;
}

