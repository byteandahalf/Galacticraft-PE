#pragma once
#include "com/mojang/minecraftpe/world/level/dimension/Dimension.h"
class CelestialBody;

class GalacticraftDimension : public Dimension {
public:
	GalacticraftDimension(Level&, DimensionId);

	virtual float getGravity();
	virtual double getMeteorFrequency();
	virtual double getFuelUsageMultiplier();
	virtual bool canSpaceshipTierPass(int);
	virtual float getFallDamageModifier();
	virtual float getSoundMuffle();
	virtual bool hasOxygenAtmosphere();
	virtual bool hasGas(void*); // TODO
	virtual float getThermalLevelModifier();
	virtual float getWindLevel();
	virtual float getSolarSize();
	virtual CelestialBody* getCelestialBody() = 0;
};
