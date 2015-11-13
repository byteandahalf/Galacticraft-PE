#include "GCFeatures.h"
#include "com/mojang/minecraftpe/world/level/biome/BiomeDecorator.h"
#include "com/mojang/minecraftpe/world/level/levelgen/feature/Feature.h"
#include "GCFeatureInfo.h"

BiomeDecorator* GCFeatures::Decorator;
std::vector<GCFeatureInfo> GCFeatures::features;

void GCFeatures::setDecorator(BiomeDecorator* decorator) {
	Decorator = decorator;
}

void GCFeatures::initFeatures() {
	//Init Feature unique_ptr here
	
	registerFeatures();
}

void GCFeatures::registerFeatures() {
	//create FeatureInfo and push feature to global vector
}

void GCFeatures::populateFeatures(BlockSource* region, Random& random, const BlockPos& pos) {
	for(GCFeatureInfo& fe : features) {
		if(fe.gentype == GCFeatureInfo::GenType::SPAN)
			Decorator->decorateDepthSpan(region, random, pos, fe.amountPerChunk, fe.feature, fe.minY, fe.maxY);
		else if(fe.gentype == GCFeatureInfo::GenType::AVERAGE)
			Decorator->decorateDepthAverage(region, random, pos, fe.amountPerChunk, fe.feature, fe.minY, fe.maxY);
	}
}
