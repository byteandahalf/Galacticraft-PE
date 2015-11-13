#pragma once
#include "Feature.h"
#include "../../../../CommonTypes.h"

class OreFeature : public Feature {
	BlockID id;
	unsigned char data;
	int veinSize;
	
public:
	OreFeature(BlockID, int);
	OreFeature(BlockID, unsigned char, int);
	
	virtual ~OreFeature();
	virtual bool place(BlockSource&, const BlockPos&, Random&) const;
};

