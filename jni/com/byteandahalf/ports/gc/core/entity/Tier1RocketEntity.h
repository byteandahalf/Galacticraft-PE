#pragma once
#include "com/mojang/minecraftpe/world/entity/Entity.h"

class Tier1RocketEntity : public Entity {
public:
	float rollAmplitude; // super
	float shipDamage; // super
	float timeUntilLaunch; // super

	Tier1RocketEntity(BlockSource&);
	Tier1RocketEntity(BlockSource&, const BlockPos&);

	virtual EntityType getEntityTypeId() const;
	virtual void readAdditionalSaveData(const CompoundTag*);
	virtual void addAdditionalSaveData(CompoundTag*);

	bool hasLaunched(); // super
};
