#include "GCFeatures.h"
#include "com/mojang/minecraftpe/world/level/biome/BiomeDecorator.h"
#include "com/mojang/minecraftpe/world/level/levelgen/feature/OreFeature.h"
#include "GCFeatureInfo.h"

std::vector<GCFeatureInfo> GCFeatures::features;

void GCFeatures::initFeatures() {
	static bool inited = false;
	if (inited) return;
	inited = true;
	registerFeatures();
}

void GCFeatures::registerFeatures() {
	// Create FeatureInfo and push to the global feature vector
	features.emplace_back(GCFeatureInfo::GenType::SPAN,
		std::unique_ptr<Feature>(new OreFeature(19, 0, 12)), 20, 0, 128);
}

void GCFeatures::populateFeatures(BiomeDecorator* decorator, BlockSource* region, Random& random, const BlockPos& pos) {
	GCFeatures::initFeatures();
	for(GCFeatureInfo& fe : features) {
		if(fe.gentype == GCFeatureInfo::GenType::SPAN)
			decorator->decorateDepthSpan(region, random, pos, fe.amountPerChunk, fe.feature, fe.minY, fe.maxY);
		else if(fe.gentype == GCFeatureInfo::GenType::AVERAGE)
			decorator->decorateDepthAverage(region, random, pos, fe.amountPerChunk, fe.feature, fe.minY, fe.maxY);
	}
}
