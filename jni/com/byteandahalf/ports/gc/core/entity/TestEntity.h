#pragma once
#include "com/mojang/minecraftpe/world/entity/Entity.h"

class TestEntity : public Entity {
public:
	TestEntity(BlockSource&);
	TestEntity(BlockSource&, const BlockPos&);

	virtual EntityType getEntityTypeId() const;
	virtual void readAdditionalSaveData(const CompoundTag*);
	virtual void addAdditionalSaveData(CompoundTag*);
};

