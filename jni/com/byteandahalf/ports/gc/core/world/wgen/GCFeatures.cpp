#include "GCFeatures.h"
#include "com/mojang/minecraftpe/world/level/biome/BiomeDecorator.h"
#include "com/mojang/minecraftpe/world/level/levelgen/feature/OreFeature.h"
#include "GCFeatureInfo.h"

std::vector<GCFeatureInfo> GCFeatures::features;
bool GCFeatures::Registered = false;

void GCFeatures::registerFeatures() {
	if(Registered)
		return;
	Registered = true;
	
	// Create FeatureInfo and push to the global feature vector
	features.emplace_back(GCFeatureInfo::GenType::SPAN, std::unique_ptr<Feature>(new OreFeature(200, 5, 7)), 21, 10, 127);
}

void GCFeatures::populateFeatures(BiomeDecorator* decorator, BlockSource* region, Random& random, const BlockPos& pos) {
	registerFeatures();
	
	for(GCFeatureInfo& fe : features) {
		if(fe.gentype == GCFeatureInfo::GenType::SPAN)
			decorator->decorateDepthSpan(region, random, pos, fe.amountPerChunk, fe.feature, fe.minY, fe.maxY);
		else if(fe.gentype == GCFeatureInfo::GenType::AVERAGE)
			decorator->decorateDepthAverage(region, random, pos, fe.amountPerChunk, fe.feature, fe.minY, fe.maxY);
	}
}
