#pragma once
#include <string>
#include <vector>
class Item;
class ItemInstance;
class Player;
struct BlockPos;
class Level;
struct Vec3;
namespace Json {
	class Value;
};

struct FoodItemComponent {
	struct Effect {
		
	};
	
	FoodItemComponent(Item&);
	
	int getNutrition();
	float getSaturationModifier();
	void use(ItemInstance&, Player&);
	void useOn(ItemInstance&, Player&, const BlockPos&, signed char, const Vec3&);
	void useTimeDepleted(ItemInstance&, Player&, Level&);
	void init(Json::Value&);
	
	Item& item; // 0
	int healAmount; // 4
	float saturation; // 8
	bool isMeat; // 12
	std::string eatSound; // 16
	std::string using_converts_to; // 20 wtf is this
	std::vector<FoodItemComponent::Effect> effects; // 24
};

