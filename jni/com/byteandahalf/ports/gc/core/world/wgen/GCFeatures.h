#pragma once
#include <vector>
class BlockSource;
class BlockPos;
class Random;
class BiomeDecorator;
class GCFeatureInfo;

class GCFeatures {
	static std::vector<GCFeatureInfo> features;
	static bool Registered;
	
public:
	static void registerFeatures();
	static void populateFeatures(BiomeDecorator*, BlockSource*, Random&, const BlockPos&);
};

