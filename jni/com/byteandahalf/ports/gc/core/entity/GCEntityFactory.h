#pragma once
#include <memory>
#include "com/mojang/minecraftpe/world/entity/EntityType.h"
class BlockSource;
class Entity;

class GCEntityFactory {
public:
	static std::unique_ptr<Entity> CreateEntity(EntityType, BlockSource&);
};

