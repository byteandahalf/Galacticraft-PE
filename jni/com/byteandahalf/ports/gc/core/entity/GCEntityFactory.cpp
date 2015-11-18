#include "GCEntityFactory.h"
#include "TestEntity.h"

std::unique_ptr<Entity> GCEntityFactory::CreateEntity(EntityType type, BlockSource& region) {
	switch(type) {
	case EntityType::TEST:
		return std::unique_ptr<Entity>(new TestEntity(region));
		
	default:
		return std::unique_ptr<Entity>{};
	}
}
