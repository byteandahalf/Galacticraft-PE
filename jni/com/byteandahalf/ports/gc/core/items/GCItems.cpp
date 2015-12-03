#include "GCItems.h"
#include "../GCUtil.h"

#include "BasicItem.h"
#include "foods/CannedCarrotItem.h"
#include "foods/CannedAppleItem.h"
#include "foods/CannedMelonItem.h"
#include "foods/CannedPotatoItem.h"

static int NO_FREE_IDS = 5000; // Out of available Item IDs

Item* GCItems::basicItem;
Item* GCItems::cannedCarrot;
Item* GCItems::cannedApple;
Item* GCItems::cannedMelon;
Item* GCItems::cannedPotato;
Item* GCItems::canister;

void GCItems::initItems() {
	basicItem = new BasicItem(470);
	cannedCarrot = new CannedCarrotItem(471);
	cannedApple = new CannedAppleItem(472);
	cannedMelon = new CannedMelonItem(473);
	cannedPotato = new CannedPotatoItem(474);
	canister = (new GalacticraftItem("canister", 475))->setIcon("canister.tin", 0);

	registerItems();
}

void GCItems::registerItems() {
	registerItem(basicItem);
	registerItem(cannedCarrot);
	registerItem(cannedApple);
	registerItem(cannedMelon);
	registerItem(cannedPotato);
	registerItem(canister);
}

Item* GCItems::registerItem(Item* item) {
	Item::mItems[item->itemId] = item;
	
	if(item->_foodDetails)
		registerFood((GCFoodItem*) item);

	return item;
}

void GCItems::registerFood(GCFoodItem* food) {
	food->_foodDetails->healAmount = food->getHealAmount();
	food->_foodDetails->saturation = food->getSaturationModifier();
	food->_foodDetails->isMeat = food->canFeedToDog();
	food->_foodDetails->eatSound = food->getFinishEatingSound();
	food->registerEatEffects();
}

