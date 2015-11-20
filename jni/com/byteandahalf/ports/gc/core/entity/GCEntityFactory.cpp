#include "GCEntityFactory.h"
#include "Tier1RocketEntity.h"

std::unique_ptr<Entity> GCEntityFactory::CreateEntity(EntityType type, BlockSource& region) {
	switch(type) {
	case EntityType::ROCKET_TIER1:
		return std::unique_ptr<Entity>(new Tier1RocketEntity(region));
		
	default:
		return std::unique_ptr<Entity>{};
	}
}
