#include "GCFeatures.h"
#include "com/mojang/minecraftpe/world/level/biome/BiomeDecorator.h"
#include "com/mojang/minecraftpe/world/level/levelgen/feature/OreFeature.h"
#include "GCFeatureInfo.h"

BiomeDecorator* GCFeatures::Decorator;
std::vector<GCFeatureInfo> GCFeatures::features;

std::unique_ptr<Feature> GCFeatures::testFeature;

void GCFeatures::setDecorator(BiomeDecorator* decorator) {
	Decorator = decorator;
}

void GCFeatures::flushFeatures() {
	// Delete existing instances of each Feature
	delete testFeature.release();
}

void GCFeatures::initFeatures() {
	// Init unique_ptrs for features
	flushFeatures();
	
	//testFeature.reset(new OreFeature(19, 0, 12));
	
	registerFeatures();
}

void GCFeatures::registerFeatures() {
	// Create FeatureInfo and push to the global feature vector
	//features.push_back(GCFeatureInfo(GCFeatureInfo::GenType::SPAN, testFeature, 20, 0, 128));
}

void GCFeatures::populateFeatures(BlockSource* region, Random& random, const BlockPos& pos) {
	for(GCFeatureInfo& fe : features) {
		if(fe.gentype == GCFeatureInfo::GenType::SPAN)
			Decorator->decorateDepthSpan(region, random, pos, fe.amountPerChunk, fe.feature, fe.minY, fe.maxY);
		else if(fe.gentype == GCFeatureInfo::GenType::AVERAGE)
			Decorator->decorateDepthAverage(region, random, pos, fe.amountPerChunk, fe.feature, fe.minY, fe.maxY);
	}
}
