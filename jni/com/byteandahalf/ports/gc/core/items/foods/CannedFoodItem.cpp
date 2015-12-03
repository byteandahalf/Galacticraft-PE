#include "CannedFoodItem.h"
#include "../GCItems.h"
#include "com/mojang/minecraftpe/world/item/ItemInstance.h"
#include "com/mojang/minecraftpe/world/entity/player/Player.h"

CannedFoodItem::CannedFoodItem(const std::string& asset, int itemId):
	GCFoodItem("cannedFood." + asset, itemId) {
	setIcon("cannedFood." + asset, 0);
}

void CannedFoodItem::useTimeDepleted(ItemInstance* stack, Level* level, Player* player) {
	Item::useTimeDepleted(stack, level, player);
	ItemInstance canisterStack(GCItems::canister, 1, 0);
	player->drop(&canisterStack);
}

