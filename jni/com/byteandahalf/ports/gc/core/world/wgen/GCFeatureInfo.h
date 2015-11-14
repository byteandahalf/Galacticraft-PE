#pragma once
#include <memory>
#include "com/mojang/minecraftpe/world/level/levelgen/feature/Feature.h"

struct GCFeatureInfo {
	enum class GenType : int {
		SPAN,
		AVERAGE
	};
	
	GCFeatureInfo(GCFeatureInfo::GenType, std::unique_ptr<Feature>, int, int, int);
	
	GCFeatureInfo::GenType gentype;
	std::unique_ptr<Feature> feature;
	int amountPerChunk;
	int minY;
	int maxY;
};

