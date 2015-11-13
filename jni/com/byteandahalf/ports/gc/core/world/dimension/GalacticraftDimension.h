#pragma once
#include "com/mojang/minecraftpe/world/level/dimension/Dimension.h"
class CelestialBody;

class GalacticraftDimension : public Dimension {
public:
	GalacticraftDimension(Level& level, DimensionId id) : Dimension(level, id) {}

	virtual float getGravity() = 0;
	virtual double getMeteorFrequency() = 0;
	virtual double getFuelUsageMultiplier() = 0;
	virtual bool canSpaceshipTierPass(int) = 0;
	virtual float getFallDamageModifier() = 0;
	virtual float getSoundMuffle() = 0;
	virtual bool hasOxygenAtmosphere() = 0;
	virtual bool hasGas(void*) = 0; // TODO
	virtual float getThermalLevelModifier() = 0;
	virtual float getWindLevel() = 0;
	virtual float getSolarSize() = 0;
	virtual CelestialBody* getCelestialBody() = 0;
};
