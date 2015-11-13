#pragma once
#include <vector>
#include <memory>
class BlockSource;
class BlockPos;
class Random;
class BiomeDecorator;
class Feature;
class GCFeatureInfo;

class GCFeatures {
	static std::vector<GCFeatureInfo> features;
	
public:
	static void initFeatures();
	static void registerFeatures();
	static void populateFeatures(BiomeDecorator*, BlockSource*, Random&, const BlockPos&);
};

