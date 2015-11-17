#pragma once
#include "com/mojang/minecraftpe/world/level/block/LiquidBlockDynamic.h"
class BlockSource;

class BlockFluidDynamicGC : public LiquidBlockDynamic {
public:
	BlockFluidDynamicGC(const std::string&, int, const std::string&);

	static int getTickDelay(LiquidBlock*, BlockSource*);
};
