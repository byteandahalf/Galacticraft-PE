#pragma once
#include "com/mojang/minecraftpe/world/level/block/LiquidBlockDynamic.h"
class BlockSource;
struct BlockPos;
struct Vec3;

class BlockFluidDynamicGC : public LiquidBlockDynamic {
public:
	BlockFluidDynamicGC(const std::string&, int, const std::string&);

	static bool isBlockSolid(BlockSource&, const BlockPos&, int);

	static int getTickDelay(LiquidBlock*, BlockSource&);
	static Vec3 _getFlow(LiquidBlock*, BlockSource&, const BlockPos&);
};
