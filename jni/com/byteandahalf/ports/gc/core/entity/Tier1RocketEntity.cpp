#include "Tier1RocketEntity.h"
#include "com/mojang/minecraftpe/world/level/BlockPos.h"

Tier1RocketEntity::Tier1RocketEntity(BlockSource& region):
	Entity(region) {
	rollAmplitude = 1.0F;
	shipDamage = 1.0F;
	timeUntilLaunch = 1.0F;
	rendererId = 100;
	_init();
}

Tier1RocketEntity::Tier1RocketEntity(BlockSource& region, const BlockPos& pos):
	Tier1RocketEntity(region) {
	setPos({pos.x, pos.y, pos.z});
}
	
EntityType Tier1RocketEntity::getEntityTypeId() const {
	return EntityType::ROCKET_TIER1;
}

void Tier1RocketEntity::readAdditionalSaveData(const CompoundTag*) {}
void Tier1RocketEntity::addAdditionalSaveData(CompoundTag*) {}

bool Tier1RocketEntity::hasLaunched() {
	return false;
}
