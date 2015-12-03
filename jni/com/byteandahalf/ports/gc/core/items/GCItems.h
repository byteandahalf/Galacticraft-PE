#pragma once
class Item;
class GCFoodItem;

class GCItems {
public:
	static Item* basicItem;
	static Item* cannedCarrot;
	static Item* cannedApple;
	static Item* cannedMelon;
	static Item* cannedPotato;
	static Item* canister;

	static void initItems();
	static void registerItems();
	
	static Item* registerItem(Item*);
	static void registerFood(GCFoodItem*);
};

