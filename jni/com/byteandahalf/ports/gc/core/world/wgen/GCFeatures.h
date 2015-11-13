#pragma once
#include <vector>
class BlockSource;
class BlockPos;
class Random;
class BiomeDecorator;
class GCFeatureInfo;

class GCFeatures {
	static BiomeDecorator* Decorator;
	static std::vector<GCFeatureInfo> features;
	
public:
	static void setDecorator(BiomeDecorator*);
	static void initFeatures();
	static void registerFeatures();
	static void populateFeatures(BlockSource*, Random&, const BlockPos&);
};

