#pragma once
class AABB;
#include "../material/Material.h"
class Entity;

class Level {
public:
	bool checkAndHandleWater(const AABB&, MaterialType, Entity*);
};

