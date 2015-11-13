#pragma once
#include "GalacticraftDimension.h"

class SpaceDimension : public GalacticraftDimension {
public:
	SpaceDimension(Level&, DimensionId);

	// Unfortunately alot of the functions that this class must override aren't virtual on MCPE :(
	// I'll fix this eventually with a lot of hooks.
	virtual const std::string& getName() const;
	virtual bool hasGas(void*); // TODO
	virtual bool hasOxygenAtmosphere();
	virtual float getSolarSize();

	virtual const Vec3& getFogColorGC() = 0;
	virtual const Vec3& getSkyColorGC() = 0;
	virtual bool hasWeather() = 0;
	virtual bool hasSunset() = 0;
	virtual long getDayLength() = 0;
	virtual bool respawnInThisDimension() = 0;
};
