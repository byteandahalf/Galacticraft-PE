#include "TestEntity.h"
#include "com/mojang/minecraftpe/world/level/BlockPos.h"

TestEntity::TestEntity(BlockSource& region):
	Entity(region) {
	tnt_ticks = 10; // Use this to fake out the Tnt renderer (I need to make my own renderer)
	rendererId = 2;
	_init();
}

TestEntity::TestEntity(BlockSource& region, const BlockPos& pos):
	TestEntity(region) {
	setPos({pos.x, pos.y, pos.z});
}
	
EntityType TestEntity::getEntityTypeId() const {
	return EntityType::TEST;
}
	
void TestEntity::readAdditionalSaveData(const CompoundTag*) {}
void TestEntity::addAdditionalSaveData(CompoundTag*) {}

