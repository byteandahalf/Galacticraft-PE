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
	static BiomeDecorator* Decorator;
	static std::vector<GCFeatureInfo> features;
	
	static std::unique_ptr<Feature> testFeature;
	
public:
	static void setDecorator(BiomeDecorator*);
	static void initFeatures();
	static void registerFeatures();
	static void populateFeatures(BlockSource*, Random&, const BlockPos&);
};

