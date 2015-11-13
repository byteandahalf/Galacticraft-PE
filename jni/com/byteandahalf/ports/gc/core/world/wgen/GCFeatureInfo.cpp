#include "GCFeatureInfo.h"

GCFeatureInfo::GCFeatureInfo(GCFeatureInfo::GenType gentype, std::unique_ptr<Feature>& feature, int amountPerChunk, int minY, int maxY) :
	gentype(gentype),
	feature(feature),
	amountPerChunk(amountPerChunk),
	minY(minY),
	maxY(maxY) {
}

