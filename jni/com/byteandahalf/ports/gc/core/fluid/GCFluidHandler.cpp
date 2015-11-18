#include "GCFluidHandler.h"
#include "com/mojang/minecraftpe/world/level/Level.h"
#include "com/mojang/minecraftpe/world/material/MaterialType.h"
#include "com/mojang/minecraftpe/world/phys/AABB.h"
#include "com/mojang/minecraftpe/world/entity/Entity.h"

void GCFluidHandler::handleEntitySwim(Entity* entity) {
	if(!entity->level.checkAndHandleWater(entity->getHandleWaterAABB(), MaterialType::OIL, entity))
		entity->wasInWater = false;
	else {
		entity->wasInWater = true;
	}
}
