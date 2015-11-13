#pragma once
#include "com/mojang/minecraftpe/world/level/block/Block.h"

class BlockBasic : public Block {
	TextureUVCoordinateSet iconBuffer[12];

public:
	BlockBasic(int, const std::string&);

	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual int getResource(Random&, int, int);
	virtual int getSpawnResourcesAuxValue(unsigned char);
	virtual int getResourceCount(Random&, int, int);
	virtual const ItemInstance& asItemInstance(BlockSource&, const BlockPos&, int) const;

	void initTextures();
};
