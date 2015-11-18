#pragma once
#include "com/mojang/minecraftpe/world/entity/Entity.h"
#include "com/mojang/minecraftpe/world/level/BlockPos.h"

// Oh no some1 call the popo he put code in a header

struct TestEntity : public Entity {
	char shit[16];
	int tnt_ticks;
	
	TestEntity(BlockSource& region, const BlockPos& pos):
		Entity(region) {
		setPos({pos.x, pos.y, pos.z});
		tnt_ticks = 10; // Use this to fake out the Tnt renderer (I need to make my own renderer)
		rendererId = 2;
		_init();
	}
	
	virtual EntityType getEntityTypeId() const {
		return EntityType::TEST;
	}
	
	virtual void readAdditionalSaveData(const CompoundTag*) {}
	virtual void addAdditionalSaveData(CompoundTag*) {}
};

