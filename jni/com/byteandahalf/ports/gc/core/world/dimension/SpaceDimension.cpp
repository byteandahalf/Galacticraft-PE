#include "SpaceDimension.h"

SpaceDimension::SpaceDimension(Level& level, DimensionId id) :
	GalacticraftDimension(level, id) {
}

const std::string& SpaceDimension::getName() const {
	return "Space"; // TODO
}

bool SpaceDimension::hasGas(void* gas) {
	return false; // TODO
}

bool SpaceDimension::hasOxygenAtmosphere() {
	return true; // TODO
}

float SpaceDimension::getSolarSize() {
	return 1.0F; // TODO
}
